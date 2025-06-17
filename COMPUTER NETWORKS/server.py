import Hamming_Code

import Cyclic_Redundancy_Check

# Import the socket library
import socket

# Next create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Socket is created successfully")

# Get local machine name
host = socket.gethostname()

# Reserve a port on the computer in this case it is 23456
# but it can be anything
port = 23456

# Next bind to the port
s.bind((host, port))
print("Socket is binded to %s" %(port))

# Put the socket into listening mode
s.listen(5)
print("Socket is listening")

# A forever loop until we interrupt it or an error occurs
while True:
    # Establish connection with client.
    c, addr = s.accept()
    print('Got connection from', addr)

    # Send a thank you message to the client.
    c.send(b'Thank you for connecting')
    
    # Receive data from the client
    msg = c.recv(1024).decode()
    print(msg)
    
    #msg1 = 11001011
    #print(msg1)
    #c.send(Hamming_Code.inputdataword(msg1).encode())
    
    # msg2_dataword = 10010111001
    # msg2_divisor = 100111
    # print(msg2_dataword, msg2_divisor)
    # msg2_codeword = Cyclic_Redundancy_Check.inputdataword(msg2_dataword, msg2_divisor)
    # data_to_send = f"{msg2_codeword}|{msg2_divisor}"
    # c.send(data_to_send.encode())
    
    msg1 = c.recv(1024).decode()
    print(msg1)
    print()
    Hamming_Code.inputcodeword(msg1)

    print()
    received_data = c.recv(1024).decode()
    msg2_codeword, msg2_divisor = received_data.split('|', 1)
    print(msg2_codeword, msg2_divisor)
    Cyclic_Redundancy_Check.inputcodeword(msg2_codeword, msg2_divisor)

    # Close the connection with the client
    c.close()