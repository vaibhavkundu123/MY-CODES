import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 2345

print('Waiting for connection')

try:
    s.connect((host, port))
except socket.error as e:
    print(str(e))

response = s.recv(1024)
print(response.decode('UTF-8'))

while True:
    message = input('Enter a message: ')
    s.send(str.encode(message))
    response = s.recv(1024)
    print(response.decode('UTF-8'))

s.close()
