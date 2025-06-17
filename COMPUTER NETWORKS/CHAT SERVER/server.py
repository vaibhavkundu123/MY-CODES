import socket

# Create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Socket is created successfully")

# Get local machine name
host = socket.gethostname()

# Reserve a port on the computer
port = 23456

# Bind to the port
s.bind((host, port))
print(f"Socket is binded to {port}")

# Put the socket into listening mode
s.listen(5)
print("Socket is listening")

# Accept a single connection
c, addr = s.accept()
print('Got connection from', addr)

# Chat loop for single client
try:
    while True:
        # Receive message from client
        client_message = c.recv(1024).decode()
        if not client_message or client_message == 'Q':
            print("Client disconnected.")
            break
            
        print(f"Client: {client_message}")

        # Send response
        server_message = input("You: ")
        if server_message == 'Q':
            break
        c.send(server_message.encode())
        
finally:
    # Clean up
    c.close()
    s.close()
    print("Connection closed")