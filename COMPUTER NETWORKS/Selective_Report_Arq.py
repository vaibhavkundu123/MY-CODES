import time
import threading
import random
from collections import OrderedDict
from queue import Queue

class SelectiveRepeatARQ:
    def __init__(self, data, window_size=4, loss_prob=0.3, timeout=1, seq_bits=3):
        self.data = data
        self.window_size = window_size
        self.seq_mod = 2 ** seq_bits
        self.loss_prob = loss_prob
        self.timeout = timeout
        
        # Sender state
        self.base = 0
        self.next_seq = 0
        self.sender_buffer = OrderedDict()
        self.ack_queue = Queue()
        self.frame_queue = Queue()
        
        # Receiver state
        self.expected_seq = 0
        self.receiver_buffer = {}
        
        # Control
        self.done = False
        self.print_lock = threading.Lock()

    def log(self, role, message):
        with self.print_lock:
            print(f"[{role}] {message}")

    def sender(self):
        while self.base < len(self.data):
            # 1. Check for timeouts and resend
            current_time = time.time()
            for seq in list(self.sender_buffer.keys()):
                entry = self.sender_buffer[seq]
                if current_time - entry['time'] > self.timeout:
                    self.log("Sender", f"Timeout! Resending {entry['frame']}")
                    if random.random() > self.loss_prob:  # Retransmission may also fail
                        self.frame_queue.put((seq, entry['frame']))
                    entry['time'] = time.time()
                    entry['retries'] += 1

            # 2. Send new packets within window
            while self.next_seq < min(self.base + self.window_size, len(self.data)):
                seq = self.next_seq % self.seq_mod
                packet = self.data[self.next_seq]
                frame = f"FRAME({seq}):{packet}"
                
                # Always track frame, even if lost
                self.sender_buffer[self.next_seq] = {
                    'frame': frame,
                    'time': time.time(),
                    'retries': 0
                }
                
                if random.random() > self.loss_prob:
                    self.log("Sender", f"Sent {frame}")
                    self.frame_queue.put((self.next_seq, frame))
                else:
                    self.log("Sender", f"LOST {frame}")
                
                self.next_seq += 1

            # 3. Process ACKs
            while not self.ack_queue.empty():
                ack_seq = self.ack_queue.get()
                if self.base <= ack_seq < self.base + self.window_size:
                    if ack_seq in self.sender_buffer:
                        del self.sender_buffer[ack_seq]
                        self.log("Sender", f"Received ACK{ack_seq % self.seq_mod}")
                    # Move window forward
                    while self.base not in self.sender_buffer and self.base < len(self.data):
                        self.base += 1

            time.sleep(0.1)

        self.done = True
        self.log("Sender", "Transmission complete")

    def receiver(self):
        while not self.done or not self.frame_queue.empty():
            try:
                seq, frame = self.frame_queue.get(timeout=0.1)
            except:
                continue

            seq_num = int(frame.split('(')[1].split(')')[0])
            packet = frame.split(':')[1]

            if seq == self.expected_seq:
                self.log("Receiver", f"Received IN-ORDER {frame}")
                self.log("Receiver", f"Delivered data: {packet}")
                self.expected_seq += 1
                # Deliver buffered packets
                while self.expected_seq in self.receiver_buffer:
                    packet = self.receiver_buffer.pop(self.expected_seq)
                    self.log("Receiver", f"Delivered buffered data: {packet}")
                    self.expected_seq += 1
            elif seq > self.expected_seq:
                self.log("Receiver", f"Buffered OUT-OF-ORDER {frame}")
                self.receiver_buffer[seq] = packet
            else:
                self.log("Receiver", f"Discarding DUPLICATE {frame}")

            # Send ACK
            if random.random() > self.loss_prob:
                self.log("Receiver", f"Sending ACK{seq_num}")
                self.ack_queue.put(seq)
            else:
                self.log("Receiver", f"ACK{seq_num} LOST")

        self.log("Receiver", "Reception complete")

    def run(self):
        sender_thread = threading.Thread(target=self.sender)
        receiver_thread = threading.Thread(target=self.receiver)
        
        sender_thread.start()
        receiver_thread.start()
        
        sender_thread.join()
        receiver_thread.join()
        print("\n=== Selective Repeat ARQ Execution Completed ===")

# Example usage
if __name__ == "__main__":
    data = ["Pkt1", "Pkt2", "Pkt3", "Pkt4", "Pkt5", "Pkt6", "Pkt7"]
    sr = SelectiveRepeatARQ(data, window_size=4, loss_prob=0.3)
    sr.run()