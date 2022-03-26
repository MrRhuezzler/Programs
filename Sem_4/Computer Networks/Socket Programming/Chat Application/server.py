import socket
import select

port = 8080

clientsToSock = {}
SockToClient = {}

socketList = []

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
host = socket.gethostname()

server.bind((host, port))
server.listen(5)

socketList.append(server)
print(host)

while True:
    readyToRead, readyToWrite, error = select.select(socketList, [], [], 0)
    for sock in readyToRead:
        if sock == server:
            print("Listening ....")
            conn, addr = sock.accept()
            socketList.append(conn)
        else:
            try:
                data = sock.recv(1024)
                if data:
                    actuallyData = data.decode('utf-8')
                    if actuallyData.startswith('#'):
                        clientsToSock[actuallyData[1:]] = sock
                        sock.send(str("Welcome, " + actuallyData[1:]).encode('utf-8'))
                    else:
                        sender, receiver, message = actuallyData.split(':')
                        r = clientsToSock.get(receiver[1:], None)
                        if r:
                            r.send(('@' + sender + ':' + message).encode('utf-8'))
                    
            except:
                continue

server.close()