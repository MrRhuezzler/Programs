import socket
import time

PORT = 9994

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print(socket.gethostname())
server.bind((socket.gethostname(), PORT))
server.listen(5)

while True:
    conn, addr = server.accept()
    print("Got a connection", addr)
    currentTime = time.ctime(time.time()) + '\r\n'
    conn.send(currentTime.encode('ascii'))
    conn.close()

input("quit...")