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
    key = {words[i]:chr(ord('a')+ i) for i in range(26)}
    
    # Read the ciphertext from 'ciphertext.txt'
    f = open('ciphertext.txt','r')
    words = f.read()
    f.close()
    temp = []

    # Iterate through the ciphertext
    for current in words:
        temp.append(current)
        
    # Decrypt the ciphertext using the key
    for i in range(len(temp)):
        if temp[i].isalpha():
            temp[i] = key[temp[i]]
        else:
            continue
        
    # Print the decrypted text
    temp[0] = temp[0].upper()
    
    # Handle newline characters by capitalizing the following character
    for j in range(len(temp)-1):
        if temp[j] == "\n":
            print(1)
            temp[j+1] = temp[j+1].upper()
            
    print(temp)
    
    # Join the decrypted characters to form the final decrypted text
    decrypted = "".join(temp)
    print(decrypted)
    
    # Write the decrypted text to 'decrypted.txt'
    f = open('decrypted.txt','w')
    f.write(decrypted)
    f.close()
    
main()