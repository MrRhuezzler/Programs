# -*- coding: utf-8 -*-
"""
Created on Fri Dec 24 09:14:59 2021

@author: 20pt25
"""

import os

encrypt_vigenere = lambda p, s : "".join([chr(65 + ((ord(c) + ord(s[i % len(s)]) - 130) % 26)) if c.isalpha() else c for i, c in enumerate(p.upper())])
decrypt_vigenere = lambda c, s : "".join([chr(65 + ((ord(c) - ord(s[i % len(s)])) % 26)) if c.isalpha() else c for i, c in enumerate(c.upper())])

if __name__ == "__main__":
    
    SHARED_KEY = "LEMON"
    
    eNd = int(input("1) Encryption\n2) Decryption\nYourChoice : "))
    
    if eNd == 1:
        fileName = input("Enter filename to encrypt : ")
        name, ext = os.path.splitext(fileName)
    
        f = open(fileName)
        content = f.read()
        f.close()
    
        encryptedContent = encrypt_vigenere(content, SHARED_KEY)
        
        ef = open(name + "_ve" + ext, "w")
        ef.write(encryptedContent)
        ef.close()
    
    elif eNd == 2:
        fileName = input("Enter filename to decrypt : ")
        name, ext = os.path.splitext(fileName)
        
        f = open(fileName)
        content = f.read()
        f.close()
        
        decryptedContent = decrypt_vigenere(content, SHARED_KEY)
        
        df = open(name + "_vd" + ext, "w")
        df.write(decryptedContent)
        df.close()
