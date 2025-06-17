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

# Accept a connection
c, addr = s.accept()
print('Got connection from', addr)

# Chat loop
while True:
    # Receive a message from the client
    client_message = c.recv(1024).decode()
    if not client_message:
        print("Client disconnected.")
        # Put the socket into listening mode
        s.listen(5)
        print("Socket is listening")

        # Accept a connection
        c, addr = s.accept()
        print('Got connection from', addr)
        
        # Receive a message from the client
        client_message = c.recv(1024).decode()
        
        print(f"Client: {client_message}")
    else:
        print(f"Client: {client_message}")

    # Send a response to the client
    server_message = input("You: ")

    if (server_message == 'Q'):
        # Close the connection
        c.close()
        s.close()
        break
    else:
        c.send(server_message.encode())