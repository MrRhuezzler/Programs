def byteStuff(flagBit: str, escBit: str, data: str):
    data = data.replace(escBit, escBit + escBit)
    data = data.replace(flagBit, escBit + flagBit)
    return data

def toBinary(data):
    binData = ""
    for i in range(len(data)):
        binData += format(ord(data[i]), 'b').zfill(8)
    return binData

def bitStuff(data):
    data = data.replace('01111', '011110')
    return data

def frame(flagBit, escBit, data):
    data = byteStuff(flagBit, escBit, data)
    data = toBinary(data)
    data = bitStuff(data)

    zeros_to_be_appended = ((len(data) - len(data) % 8) + 8)
    data = data.zfill(zeros_to_be_appended)

    frame_size = 16
    print(len(data))
    for i in range(0, len(data), frame_size):
        print(format(ord(flagBit), 'b').zfill(8) + ' ' + data[i : i + frame_size]  + ' ' + format(ord(flagBit), 'b').zfill(8))

print(format(ord('!'), 'b'))
frame('|', '#', '#He|pMe!')
