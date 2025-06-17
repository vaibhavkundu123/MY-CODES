import time
import threading
import random
from queue import Queue


class StopAndWaitARQ:
    def __init__(self, data, loss_prob=0.3, timeout=2):
        self.data = data
        self.seq_num = 0
        self.expected_seq = 0
        self.frame_queue = Queue()
        self.ack_queue = Queue()
        self.loss_prob = loss_prob
        self.timeout = timeout
        self.done = False
        self.print_lock = threading.Lock()
    
    def log(self, role, message):
        with self.print_lock:
            print(f"[{role}] {message}")
    
    def sender(self):
        for packet in self.data:
            retransmit = True
            while retransmit:
                frame = f"{self.seq_num}:{packet}"
                self.log("Sender", f"Created frame: {frame}")
                
                if random.random() > self.loss_prob:
                    self.log("Sender", f"Sent frame: {frame}")
                    self.frame_queue.put(frame)
                else:
                    self.log("Sender", f"Frame {frame} LOST")
                    continue
                
                start_time = time.time()
                while time.time() - start_time < self.timeout:
                    if not self.ack_queue.empty():
                        ack = self.ack_queue.get()
                        if ack == self.seq_num:
                            self.log("Sender", f"ACK{ack} received")
                            retransmit = False
                            break
                        else:
                            self.log("Sender", f"Wrong ACK{ack} received")
                
                if retransmit:
                    self.log("Sender", f"Timeout! Resending frame: {frame}")
            
            self.seq_num = 1 - self.seq_num
        
        self.done = True
        self.log("Sender", "All packets successfully transmitted")
    
    def receiver(self):
        while not self.done or not self.frame_queue.empty():
            if self.frame_queue.empty():
                time.sleep(0.5)
                continue
            
            frame = self.frame_queue.get()
            seq, data = frame.split(':', 1)
            seq = int(seq)
            
            if seq == self.expected_seq:
                self.log("Receiver", f"Received frame {seq}: {data}")
                self.log("Receiver", "Delivering to network layer")
                self.expected_seq = 1 - self.expected_seq
            else:
                self.log("Receiver", f"Duplicate frame {seq} received")
            
            if random.random() > self.loss_prob:
                self.log("Receiver", f"Sending ACK{seq}")
                self.ack_queue.put(seq)
            else:
                self.log("Receiver", f"ACK{seq} LOST")
    
    def run(self):
        sender_thread = threading.Thread(target=self.sender)
        receiver_thread = threading.Thread(target=self.receiver)
        
        sender_thread.start()
        receiver_thread.start()
        
        sender_thread.join()
        receiver_thread.join()


if __name__ == "__main__":
    data = ["Hello", "World", "Test", "ARQ", "Final"]
    protocol = StopAndWaitARQ(data, loss_prob=0.2, timeout=1)
    protocol.run()
    print("\n=== ARQ Protocol Execution Completed ===")