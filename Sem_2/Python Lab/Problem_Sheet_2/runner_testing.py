import subprocess

# child = subprocess.Popen(['python', '3.py'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)

# inputs = "2\n3"

# output = []

# child.stdin.write(inputs.encode('utf-8'))
# child.stdin.close()

# output.append(child.stdout.read().decode('utf-8'))
# child.wait()

# output.append(child.stdout.read().decode('utf-8'))

# print(output)


from subprocess import Popen, PIPE

out = []

p = Popen(['python', '3.py'], stdin = PIPE, stdout = PIPE)

p.stdin.write("2\n".encode('utf-8'))
# p.stdin.close()
out.append(p.stdout.read())

p.stdin.write("3\n".encode('utf-8'))
out.append(p.stdout.read())

p.stdin.close()
out.append(p.stdout.read())

print(out)