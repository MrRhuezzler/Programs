import socket
import threading

port = 8080
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = input("Server Host: ")
client.connect((host, port))

name = input("Name : ")

STOP_THREADS = False

def recieveMessages(conn):
    global STOP_THREADS
    while not STOP_THREADS:
        try:
            data = conn.recv(1024)
            print(data.decode('utf-8'))
        except:
            if STOP_THREADS:
                break
            continue

t = threading.Thread(target=recieveMessages, args=(client,))
t.start()

# Sending nick
client.send(str('#' + name).encode('utf-8'))
while True:
    message = input("")
    if message == "QUIT":
        STOP_THREADS = True
        break

    client.send((name + ':' + message).encode('utf-8'))

t.join()
