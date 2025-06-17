import time
import threading
from queue import Queue


class StopAndWait:
    def __init__(self, data):
        self.data = data
        self.seq = 0
        self.expected_seq = 0
        self.frame_queue = Queue()
        self.ack_queue = Queue()
        self.done = False
        self.print_lock = threading.Lock()

    def log(self, role, message):
        with self.print_lock:
            if message:
                print(f"[{role}] {message}")
            else:
                print()

    def sender(self):
        for packet in self.data:
            self.log("Sender", "1. Waiting for event...")
            time.sleep(0.7)
            
            self.log("Sender", "2. Event: RequestToSend detected")
            self.log("Sender", f"3. Creating frame with seq {self.seq}")
            frame = f"FRAME[{self.seq},{packet}]"
            self.log("Sender", f"4. Sending frame: {frame}")
            self.frame_queue.put(frame)

            while True:
                self.log("Sender", "5. Waiting for ACK...")
                try:
                    ack = self.ack_queue.get(timeout=2)
                    if ack == self.seq:
                        self.log("Sender", f"6. ACK{self.seq} received")
                        self.log("", "")
                        self.seq = 1 - self.seq
                        break
                    else:
                        self.log("Sender", f"6. Wrong ACK{ack} received, resending")
                        self.frame_queue.put(frame)
                except:
                    self.log("Sender", "6. Timeout, resending frame")
                    self.frame_queue.put(frame)

        self.done = True
        self.log("Sender", "All packets sent and acknowledged")

    def receiver(self):
        initial_delay = True
        while not self.done or not self.frame_queue.empty():
            if initial_delay:
                time.sleep(0.3)
                initial_delay = False
                
            self.log("Receiver", "1. Waiting for event...")
            try:
                frame = self.frame_queue.get(timeout=0.9)
                self.log("Receiver", "2. Event: ArrivalNotification detected")
                self.log("Receiver", f"3. Received frame: {frame}")
                
                seq = int(frame.split('[')[1].split(',')[0])
                if seq == self.expected_seq:
                    self.log("Receiver", "4. Extracting data")
                    self.log("Receiver", "5. Delivering to network layer")
                    self.expected_seq = 1 - self.expected_seq
                else:
                    self.log("Receiver", "4. Duplicate frame detected")
                
                self.log("Receiver", f"6. Sending ACK{seq}")
                self.ack_queue.put(seq)
                time.sleep(0.4)
                
            except:
                continue

        self.log("Receiver", "Transmission complete")


data = ["Hello", "World", "Test"]
protocol = StopAndWait(data)

sender_thread = threading.Thread(target=protocol.sender)
receiver_thread = threading.Thread(target=protocol.receiver)

sender_thread.start()
receiver_thread.start()

sender_thread.join()
receiver_thread.join()

print("\n=== Protocol execution completed ===")