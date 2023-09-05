"""
Student: orel twito
Assignment no. 4
Program: matrix.py
"""

def main():
    # Read the key from 'key.txt'
    f = open('key.txt','r')
    words = f.read()
    f.close()
    
    # Create a dictionary for character mapping
    key = {chr(ord('a')+ i):words[i] for i in range(26)}
    
    # Read the plaintext from 'plaintext.txt'
    f = open('plaintext.txt','r')
    words = f.read()
    f.close()
    
    # Print the key and plaintext for debugging
    print(key)
    print(words)
    
    temp = []
    
    # Iterate through the plaintext
    for current in words:
        temp.append(current)
    
    # Decrypt the plaintext using the key
    for i in range(len(temp)):
        if temp[i].isalpha():
            # Convert uppercase characters to lowercase
            if temp[i].isupper():
                temp[i] = temp[i].lower()
            temp[i] = key[temp[i]]
    
    # Join the encrypted characters to form the final encrypted text
    encrypted = "".join(temp)
    
    print(encrypted)
    
    # Write the encrypted text to 'ciphertext.txt'
    f = open('ciphertext.txt','w')
    f.write(encrypted)
    f.close()

# Call the main function to execute the encryption
main()
