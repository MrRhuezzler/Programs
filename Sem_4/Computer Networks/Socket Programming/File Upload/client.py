import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = input("Server IP : ")
port = int(input("Server PORT : "))
client.connect((host, port))

hasFinished = False

while not hasFinished:
    payload = input("Client > ")
    if payload == 'quit':
        client.close()
        break

    client.send(payload.encode('utf-8'))
    try:
        returnedValue = client.recv(1024).decode('utf-8')
        print(returnedValue)
    except:
        continue

print(f"Server : {returnedValue}")

input("quit...")
