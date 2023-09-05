"""
Student: orel twito
Assignment no. 3
Program: ChekingPassword.py
"""

# Function to determine the placement of uppercase letters in the password.
def placeLetters(password):     
    if password[0].isupper():
        return "S"
    if password[-1].isupper():
        return "E"
    for i in password:
        if i.isupper():
            return "M"
    else: 
        return '-1'

# Function to count the sequence of special characters in the password.
def sequenceChars(password): 
    sequenceChars = 0
    count = 0
    tempCount = 0
    for i in password:
        if i in "#@$%&":
            count += 1
            tempCount += 1
        else:
            if tempCount > count:
                sequenceChars = tempCount
                tempCount = 0
    if tempCount > sequenceChars:
        sequenceChars = tempCount
    if count >= 2:
        return sequenceChars
    else: 
        return 0  


# Function to count the sequence of digits in the password.
def sequenceDigits(password):        
    count = 0
    tempCount = 0
    for i in password:
        if i.isnumeric():
            tempCount += 1
        else:
            if tempCount > count:
                count = tempCount
                tempCount = 0
    if tempCount > count:
        count = tempCount
    return count
    

# Function to check the password against various criteria.
def chekingPass():
    numbersOfErrors = 0             
    ExpOfErrors = []               
    password = input("Enter password: ")
    lenPass = len(password)        
    numOfDigits = sequenceDigits(password)  

    numOfChars = sequenceChars(password)    

    upperLetter = placeLetters(password)    

    
    if lenPass < 6:                         
        ExpOfErrors.append("Short password")
        numbersOfErrors += 1
    elif lenPass > 12:
        ExpOfErrors.append("long password")
        numbersOfErrors += 1
    
    if numOfDigits == 0:                    
        ExpOfErrors.append("has no digit")
        numbersOfErrors += 1
    elif numOfDigits > 3:
        ExpOfErrors.append("the sequence of digit more then 3")
        numbersOfErrors += 1
        
    if numOfChars == 0:                     
        ExpOfErrors.append("password has to be at list 2 chars")
        numbersOfErrors += 1
    elif numOfChars > 2:
        ExpOfErrors.append("too much sequenceChars")
        numbersOfErrors += 1
                                                
    if upperLetter == "-1":                              
        ExpOfErrors.append("has no upper letter")
        numbersOfErrors += 1
    elif upperLetter == 'S':
        ExpOfErrors.append("has an upper letter at the beginning")
        numbersOfErrors += 1
    elif upperLetter == 'E':
        ExpOfErrors.append("has an upper letter at the end")
        numbersOfErrors += 1 
        
    if numbersOfErrors == 0:                
        print("\nGood password")
    else:                                   
        print(f'Password had failed in {numbersOfErrors} criteria:\n')
        for i in ExpOfErrors:
            print(i,end=("\n""\n"))
             
def main():
    chekingPass()
    
main()
