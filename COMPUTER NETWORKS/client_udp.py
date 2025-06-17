import socket

# Create a UDP socket object
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Get local machine name
host = socket.gethostname()

# Define the port on which we want to connect
port = 23456

# Server address tuple
server_addr = (host, port)

# Send initial message to server
s.sendto(b'Hello', server_addr)

# Receive response from server
msg, addr = s.recvfrom(1024)
print(msg.decode())

# Send final message to server
s.sendto(b'Welcome. Bye!', server_addr)

# Close the socket
s.close()