import socket

# Create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Get local machine name
host = socket.gethostname()

# Define the port on which we want to connect
port = 23456

# Connect to the server
s.connect((host, port))
print("Connected to the server.")

# Chat loop
while True:
    # Send a message to the server
    client_message = input("You: ")
    if client_message == 'Q':
        # Close the connection
        s.close()
        break
    else:
        s.send(client_message.encode())


    # Receive a response from the server
    server_message = s.recv(1024).decode()
    if not server_message:
        print("Server disconnected.")
        break
    print(f"Server: {server_message}")