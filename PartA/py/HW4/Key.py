"""
Student: orel twito
Assignment no. 4
Program: matrix.py
"""
import random
def main():
    temp = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    
    words = []
    
    # Randomly shuffle the letters to create a key.
    for i in range(26):
        num = random.randint(0, len(temp)-1)
        words.append(temp[num])
        temp.pop(num)    
        
    chrwords = "".join(words)
    print(chrwords)
    f = open('key.txt','w')
    f.write(chrwords)
    f.close()
    
main()