import threading
import socket

PORT = 8080

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
HOST = socket.gethostname()
server.bind((HOST, PORT))
server.listen(5)
server.settimeout(2)

print(f"Listening on {HOST}:{PORT}")

MAC_TABLE = dict()

def handle_client(conn, addr):
    print(f"{addr} connected")
    while True:
        global stop_threads
        if stop_threads:
            conn.close()
            break

        try:
            requestString = conn.recv(1024).decode('utf-8')
            print(requestString)
            if requestString.startswith('GET '):
                requestString = requestString.replace('GET ', '')
                if (x := MAC_TABLE.get(requestString, None)):
                    conn.send(x.encode('utf-8'))
                else:
                    conn.send(f"[404] Couldn't find {requestString}".encode('utf-8'))

            elif requestString.startswith('PUT '):
                requestString = requestString.replace('PUT ', '')
                payload = requestString.split(' ')
                MAC_TABLE[payload[0]] = payload[1]
                conn.send(f"[201] Updated MAC Table. Terminate Connection.".encode('utf-8'))
            else:
                conn.close()
                break
        except:
            continue


threads = []
stop_threads = False
while True:
    try:
        conn, addr = server.accept()
        if conn:
            print(f"{addr} connected")
            t = threading.Thread(target=handle_client, args=(conn, addr))
            t.start()
            threads.append(t)

    except KeyboardInterrupt:
        stop_threads = True
        break

    except:
        continue

print("sdfsdf")
for i in threads:
    i.join()

server.close()
print("Exited Successfully")