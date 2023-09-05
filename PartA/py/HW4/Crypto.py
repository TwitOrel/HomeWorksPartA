"""
Student: orel twito
Assignment no. 4
Program: crypto.py
"""

# Function to decrypt ciphertext using the key.
def decrypting():
    f = open('key.txt','r')
    words = f.read()
    f.close()
    key = {words[i]:chr(ord('a')+ i) for i in range(26)}
    
    f = open('ciphertext.txt','r')
    words = f.read()
    f.close()
    temp = []

    for current in words:
        temp.append(current)
    for i in range(len(temp)):
        if temp[i].isalpha():
            temp[i] = key[temp[i]]
        else:
            continue
        
    decrypted = "".join(temp)
    
    f = open('decrypted.txt','w')
    f.write(decrypted)
    f.close()
    
    
# Function to encrypt plaintext using the key.
def encrypting():
    f = open('key.txt','r')
    words = f.read()
    f.close()
    key = {chr(ord('a')+ i):words[i] for i in range(26)}
    
    f = open('plaintext.txt','r')
    words = f.read()
    f.close()
    temp = []
    
    for current in words:
        temp.append(current)
        
    for i in range(len(temp)):
        if temp[i].isalpha():
            if temp[i].isupper():
                temp[i] = temp[i].lower()
            temp[i] = key[temp[i]]
        else:
            continue
        
    encrypted = "".join(temp)
    
    f = open('ciphertext.txt','w')
    f.write(encrypted) 
    f.close()

# Function to generate a random key.
def pkey():
    import random
    temp = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    words = []
    for i in range(26):
        num = random.randint(0, len(temp)-1)
        words.append(temp[num])
        temp.pop(num)    
    chrwords = "".join(words)
    f = open('key.txt','w')
    f.write(chrwords)
    f.close()


# Main function for user interaction.
def crypto(): 

    print("Hi wolcome to crypto")
    print("we may offer you to creat Key, encrypt text or decrypt text")
    print("for creat Key    : enter k\n"'for encrypt text : enter e\n''for decrypt text : enter d')
    while True:
        choose = input("with one you want: ")
        if choose.lower() == 'k':
             pkey()
        elif  choose.lower() == 'e':
            encrypting()
        elif  choose.lower() == 'd':
            decrypting()
        else:
            print("Bye!")
            break
        
def main():
    crypto()
    
main()