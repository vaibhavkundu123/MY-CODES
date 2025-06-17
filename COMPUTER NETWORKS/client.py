import Hamming_Code

import Cyclic_Redundancy_Check

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
msg = s.recv(1024).decode()
print(msg)

# Send a thank you message to the server.
s.send(b'Welcome. Bye!')

#msg1 = s.recv(1024).decode()
#print(msg1)
#print()
#Hamming_Code.inputcodeword(msg1)

# received_data = s.recv(1024).decode()
# msg2_codeword, msg2_divisor = received_data.split('|', 1)
# print(msg2_codeword, msg2_divisor)
# Cyclic_Redundancy_Check.inputcodeword(msg2_codeword, msg2_divisor)

msg1 = 11001011
print(msg1)
s.send(Hamming_Code.inputdataword(msg1).encode())

print()
msg2_dataword = 10010111001
msg2_divisor = 100111
print(msg2_dataword, msg2_divisor)
msg2_codeword = Cyclic_Redundancy_Check.inputdataword(msg2_dataword, msg2_divisor)
data_to_send = f"{msg2_codeword}|{msg2_divisor}"
s.send(data_to_send.encode())

# Close the connection
s.close()