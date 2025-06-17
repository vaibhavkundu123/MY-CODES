import Hamming_Code

# Import socket module
import socket
# Create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Get local machine name
host = socket.gethostname()

# Define the port on which we want to connect
port = 23456

# connect to the server on local computer
s.connect((host, port))

# Receive data from the server
msg = s.recv(1024)
print(msg)

# Send a thank you message to the server.
s.send(b'Welcome to use our server. Bye!')

msg1 = s.recv(1024)
print(msg1)
#Hamming_Code.inputdataword(11001011)

#s.send(b'110001011110')

# Close the connection
s.close()