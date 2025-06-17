import time
import threading
import random
from collections import deque

class GoBackNARQ:
    def __init__(self, data, window_size=4, loss_prob=0.3, timeout=2, seq_bits=4):
        self.data = data
        self.window_size = window_size
        self.base = 0
        self.next_seq = 0
        self.loss_prob = loss_prob
        self.timeout = timeout
        self.seq_mod = 2 ** seq_bits
        self.timers = {}
        self.sender_queue = deque()
        self.receiver_queue = deque()
        self.expected_seq = 0
        self.done = False
        self.lock = threading.Lock()
        self.print_lock = threading.Lock()

    def log(self, role, message):
        with self.print_lock:
            print(f"[{role}] {message}")

    def sender(self):
        while self.base < len(self.data):
            # Send packets within current window
            while self.next_seq < min(self.base + self.window_size, len(self.data)):
                seq_num = self.next_seq % self.seq_mod
                if self.next_seq not in self.timers:
                    packet = self.data[self.next_seq]
                    frame = f"FRAME({seq_num}):{packet}"
                    
                    if random.random() > self.loss_prob:
                        self.log("Sender", f"Sent {frame}")
                        self.sender_queue.append(frame)
                        self.timers[self.next_seq] = time.time()
                    else:
                        self.log("Sender", f"LOST {frame}")
                    
                    self.next_seq += 1

            # Check for timeouts and handle retransmissions
            current_time = time.time()
            for seq in list(self.timers.keys()):
                if current_time - self.timers[seq] > self.timeout:
                    self.log("Sender", f"Timeout! Resending window starting at {self.base}")
                    self.next_seq = self.base  # Reset to base for full window retransmission
                    # Clear timers for all unacknowledged packets
                    for key in list(self.timers.keys()):
                        if key >= self.base:
                            del self.timers[key]
                    break

            # Process ACKs with proper validation
            while self.receiver_queue:
                ack = self.receiver_queue.popleft()
                ack_abs = ack  # Absolute sequence number
                ack_seq = ack % self.seq_mod
                
                # Validate ACK is in valid range
                if self.base <= ack_abs < self.base + self.window_size:
                    self.log("Sender", f"Received valid ACK{ack_seq}")
                    new_base = ack_abs + 1
                    # Remove acknowledged packets from timers
                    for seq in list(self.timers.keys()):
                        if seq < new_base:
                            del self.timers[seq]
                    self.base = new_base
                    self.next_seq = max(self.next_seq, self.base)
                else:
                    self.log("Sender", f"Ignoring invalid ACK{ack_seq} (base={self.base})")

            time.sleep(0.1)

        self.done = True
        self.log("Sender", "Transmission complete")

    def receiver(self):
        while not self.done or self.sender_queue:
            if not self.sender_queue:
                time.sleep(0.1)
                continue

            frame = self.sender_queue.popleft()
            seq_str = frame.split('(')[1].split(')')[0]
            seq = int(seq_str)
            data = frame.split(':')[1]
            current_expected = self.expected_seq % self.seq_mod

            if seq == current_expected:
                self.log("Receiver", f"Received IN-ORDER {frame} (expected {current_expected})")
                self.log("Receiver", f"Delivered data: {data}")
                self.expected_seq += 1
                ack = self.expected_seq - 1  # Cumulative ACK
            else:
                self.log("Receiver", f"Discarding OUT-OF-ORDER {frame} (expected {current_expected})")
                ack = self.expected_seq - 1  # Last valid sequence

            # Send cumulative ACK with absolute sequence number
            ack_seq = ack % self.seq_mod
            if random.random() > self.loss_prob:
                self.log("Receiver", f"Sending ACK{ack_seq} (absolute={ack})")
                self.receiver_queue.append(ack)
            else:
                self.log("Receiver", f"ACK{ack_seq} LOST")

    def run(self):
        sender_thread = threading.Thread(target=self.sender)
        receiver_thread = threading.Thread(target=self.receiver)
        
        sender_thread.start()
        receiver_thread.start()
        
        sender_thread.join()
        receiver_thread.join()
        print("\n=== GBN ARQ Execution Completed ===")

# Example usage
if __name__ == "__main__":
    data = ["Pkt1", "Pkt2", "Pkt3", "Pkt4", "Pkt5", "Pkt6", "Pkt7"]
    gbn = GoBackNARQ(data, window_size=5, loss_prob=0.2, timeout=1)
    gbn.run()