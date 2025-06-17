import socket
import threading

thread_counter = 0
lock = threading.Lock()


def handle_client(c, addr, thread_num):
    try:
        print(f"Thread #{thread_num} handling {addr}")
        while True:
            client_message = c.recv(1024).decode()
            if not client_message or client_message == 'Q':
                print(f"Thread #{thread_num}: Client {addr} disconnected.")
                break
            print(f"[Thread #{thread_num}] Client {addr}: {client_message}")
            server_message = input(f"Reply to {addr} (Thread #{thread_num}): ")
            c.send(server_message.encode())
    finally:
        c.close()


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 23456

s.bind((host, port))
s.listen(5)
print("Socket is listening")

while True:
    c, addr = s.accept()
    
    with lock:
        thread_counter += 1
        current_thread_num = thread_counter
    
    print(f'New connection from {addr} -> Thread #{current_thread_num}')
    client_thread = threading.Thread(
        target=handle_client, 
        args=(c, addr, current_thread_num)
    )
    client_thread.start()