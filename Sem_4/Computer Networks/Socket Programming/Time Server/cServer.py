import threading
import socket

PORT = 9994

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((socket.gethostname(), PORT))

clients = {}

server.listen(5)
server.setblocking(False)

def accept_connections():
    while True:
        print("listening for connections....")
        conn, addr = server.accept()
        if conn:
            nick = conn.recv(1024)
            nick = nick.decode('ascii')
            clients[nick] = {'conn' : conn, 'addr' : addr}
            print(nick, " just joined !")

t = threading.Thread(target=accept_connections)
t.start()

while True:
    for client in clients:
        try:
            data = clients[client]['conn'].recv(1024)
        except:
            continue
        else:
            data = data.decode('ascii')
            nick, text = data.split('.')
            clients[nick.strip()]['conn'].send(str(client + " : " + text).encode('ascii'))

t.join()
for client in clients:
    clients[client]['conn'].close()
