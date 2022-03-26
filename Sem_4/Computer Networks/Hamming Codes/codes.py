def intToBinary(ascii: int):
    return bin(ascii).replace('0b', '').zfill(8)

def stringToAsciiBinary(message: str):
    binary_str = ""
    for ch in message:
        binary_str += intToBinary(ord(ch))
    
    return binary_str

def getNoOfParities(m: int):
    r = 1
    isGreater = lambda r, m: pow(2, r) >= m + r + 1
    while not isGreater(r, m):
        r += 1
    return [pow(2, i) for i in range(r)]

def hamming(message : str):
    dataBits = stringToAsciiBinary(message)
    parities = getNoOfParities(len(dataBits))
    codeWordLength = len(parities) + len(dataBits)
    codeWord = ["0"] * codeWordLength
    index = 0
    for i in range(1, codeWordLength + 1):
        if i not in parities:
            codeWord[i - 1] = dataBits[index]
            index += 1

    for parity in parities:
        paritySum = 0
        i = parity
        while i < codeWordLength + 1:
            for j in range(parity):
                if (i < codeWordLength + 1):
                    paritySum += 1 if codeWord[i - 1] == '1' else 0
                else:
                    break
                i += 1
            i += parity

        if paritySum % 2 == 0:
            codeWord[parity - 1] = '0'
        else:
            codeWord[parity - 1] = '1'

    return ''.join(codeWord)


def verifyHammingCode(message : str):
    i = 0
    x = pow(2, i)
    codeWordLength = len(message)
    isOkay = True
    number = ""
    databits = ""
    parities = []
    while x < codeWordLength:
        parities.append(x)
        j = x
        paritySum = 0
        while j < codeWordLength + 1:
            for k in range(x):
                if (j < codeWordLength + 1):
                    paritySum += 1 if message[i - 1] == '1' else 0
                else:
                    break
                j += 1
            j += x

        if paritySum % 2 != 0:
            number += "1"
            isOkay = False
        else:
            number += "0"

        i += 1
        x = pow(2, i)

    if not isOkay:
        print("Possible Error @ ", int(number, 2))
    else:
        for i in range(len(message)):
            if i not in parities:
                databits += message[i]

        return message

a = hamming("F")
print(a)
b = verifyHammingCode(a)
print(b)
