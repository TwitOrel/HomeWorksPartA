"""
Student: orel twito
Assignment no. 3
Program: stats.py
"""

# Define a function to check if a list is in increasing, decreasing, or no particular order.
def isDecreaseOrIncrease(myList):           
    decrease = True
    increase = True
    
    for i in range(len(myList)-1):
        if myList[i] < myList[i+1]:
            decrease = False
        if myList[i] > myList[i+1]:
            increase = False
        
    if increase:
        return "this is Increase Series"
    if decrease:
        return "this is Decrease Series"
    if (increase and decrease) or (not decrease and not increase):
        return "this is not Increase or Decrease Series"
    
    
# Define a function to find the lowest number and its position in the list.
def getLowest(myList):                 
    count = 1
    cell = 1
    lowestNum = myList[0]
    for j in range(1, len(myList)):
        count +=1
        if lowestNum > myList[j]:
            lowestNum = myList[j]
            cell = count

    return f"the Loewst num is {lowestNum} in cell {cell} "


# Define a function to find the highest number and its position in the list.
def getHighest(myList):             #המספר הגבוהה ומיקומו
    count = 1
    cell = 1
    highestNum = myList[0]
    for j in range(1,len(myList)):
        count +=1
        if highestNum < myList[j]:
            highestNum = myList[j]
            cell = count 
            
    return f"the Highest num is {highestNum} in cell {cell} "
            

# Define a function to calculate the average of numbers in the list.
def getAverage(myList):             
    sumList = 0
    
    for j in myList:
        sumList += j
        average = sumList/len(myList)
        average = '%.2f'%average
    return f"the Average is: {average}"
    

# Define a function to convert a space-separated string of numbers into a list of floats.
def stringToListOfFloats(str1):         
    list1 = []
    temp = ''
   
    for i in str1:
        if i == ' ':
            list1.append(float(temp))
            temp = ''
        else:
            temp+=i
    list1.append(float(temp))
    
    return list1


def stats():
    string = input("enter numbers seperated by spaces: ")
    myList = stringToListOfFloats(string)
    print(getAverage(myList))
    print(getHighest(myList))
    print(getLowest(myList))
    print(isDecreaseOrIncrease(myList))
    
    
def main():
    stats()
    
main()