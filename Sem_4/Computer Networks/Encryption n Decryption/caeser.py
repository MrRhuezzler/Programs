# -*- coding: utf-8 -*-
"""
Created on Fri Dec 24 08:44:55 2021

@author: Rhubanraj
"""

import os

encrypt_caesar = lambda p, k : "".join([chr(65 + (((ord(i) - 65) + k) % 26)) if i.isalpha() else i for i in p.upper()])
decrypt_caesar = lambda c, k : "".join([chr(65 + (((ord(i) - 65) - k) % 26)) if i.isalpha() else i for i in c.upper()])

if __name__ == "__main__":
    KEY = 3
    
    eNd = int(input("1) Encryption\n2) Decryption\nYourChoice : "))
    
    if eNd == 1:
        fileName = input("Enter filename to encrypt : ")
        name, ext = os.path.splitext(fileName)
    
        f = open(fileName)
        content = f.read()
        f.close()
    
        encryptedContent = encrypt_caesar(content, KEY)
        
        ef = open(name + "_ce" + ext, "w")
        ef.write(encryptedContent)
        ef.close()
    
    elif eNd == 2:
        fileName = input("Enter filename to decrypt : ")
        name, ext = os.path.splitext(fileName)
        
        f = open(fileName)
        content = f.read()
        f.close()
        
        decryptedContent = decrypt_caesar(content, KEY)

        df = open(name + "_cd" + ext, "w")
        df.write(decryptedContent)
        df.close()
