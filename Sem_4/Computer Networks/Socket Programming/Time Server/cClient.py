import socket
import threading

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = input("Server IP : ")
port = int(input("Server PORT : "))
nick = input("Your nick : ")

client.connect((host, port))                   
client.send(nick.encode('ascii'))

def recv_from_server():
    while True:
        msg = client.recv(1024)
        if msg:
            msg = msg.decode('ascii')
            print(msg)

t = threading.Thread(target=recv_from_server)
t.start()

while True:
    message = input("[" + nick + "] : ")
    client.send(message.encode('ascii'))

t.join()
client.close()
