import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = input("Server IP : ")
port = int(input("Server PORT : "))
client.connect((host, port))                               

tm = client.recv(1024)

client.close()

print("The time got from the server is %s" % tm.decode('ascii'))

input("quit...")