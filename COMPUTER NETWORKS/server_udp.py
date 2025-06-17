import socket

# Create a UDP socket object
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
print("Socket is created successfully")

# Get local machine name
host = socket.gethostname()

# Reserve a port on the computer
port = 23456

# Bind to the port
s.bind((host, port))
print(f"Socket is binded to {port}")

# Receive initial message from client
msg, addr = s.recvfrom(1024)
print('Got connection from', addr)
print(msg.decode())

# Send thank you message to client
s.sendto(b'Thank you for connecting', addr)

# Receive final message from client
msg, addr = s.recvfrom(1024)
print(msg.decode())

# Close the socket
s.close()