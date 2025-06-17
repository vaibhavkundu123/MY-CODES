import socket
from _thread import *

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 2345
ThreadCount = 0

try:
    s.bind((host, port))
except socket.error as e:
    print(str(e))

print('Waitiing for clients..')
s.listen(5)


def threaded_client(connection):
    connection.send(str.encode('Welcome to the Server'))
    while True:
        data = connection.recv(1024)
        print('Client ' + data.decode('UTF-8'))
        #print(data.decode('UTF-8'))
        reply = 'Echo message: ' + data.decode('UTF-8')
        if not data:
            break
        connection.sendall(str.encode(reply))
    connection.close()

while True:
    c, add = s.accept()
    print('Connected to: ' + add[0] + ':' + str(add[1]))
    start_new_thread(threaded_client, (c, ))
    ThreadCount += 1
    print('Client Number: ' + str(ThreadCount))
s.close()
