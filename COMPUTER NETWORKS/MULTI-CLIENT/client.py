import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port = 23456

s.connect((host, port))
print("Connected to the server.")

while True:
    client_message = input("You: ")
    if client_message == 'Q':
        s.close()
        break
    s.send(client_message.encode())
    server_message = s.recv(1024).decode()
    print(f"Server: {server_message}")