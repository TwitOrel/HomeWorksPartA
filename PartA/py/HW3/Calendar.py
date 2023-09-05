"""
Student: orel twito
Assignment no. 3
Program: calendar.py
"""

# Define a function to print the calendar for a specific month and year.
def printCalendar(days,month,year,countDays,monthsNames): 
    days = (days+1)%7                           
    
    print(f"{month}  {year}")
    print(" ")
    print(days)
    print("Su  Mo  Tu  We  Th  Fr  Sa")


    for j in range(len(monthsNames)):
        if month == monthsNames[j]:
            month = countDays[j]
            break
    counter = 1    
    print((days)*4*" ",end=(""))
    
    while counter <= month:
        for j in range(days,7):
            if counter > month:
                break
            print(f"{counter}  ",end=(""))
            if counter < 10:    
                print(" ",end=(""))
            counter += 1 
            days = 0
        print(" ")
        
        
# Define a function to convert the last year (in months) into days.
def monthToDays(month,year, countMonths, monthsNames):      
    daysOfLastYear = 0
    
    
    for i in range(len(monthsNames)):
        if monthsNames[i] == month:
            break
        daysOfLastYear += countMonths[i]
        
    return daysOfLastYear
            

# Define a function to convert the number of years (including the last year counted in months) into days.
def yearsToDays(year):                  
    fullYears = year - 1900 
    leapYears = (fullYears-1)//4 
       
    return ((fullYears*365) + (leapYears))

    
# Define a function to check if a year is a leap year.
def isItLeapYear(year):                     #בודקת אם LEAP YEAR
    if (year%400 == 0) or ((year%4 == 0) and (year%100 != 0)):
        februar = 29
    else:
        februar = 28
        
    return februar

# Define the main function for user interaction.
def calendar():
    month = input("choose month: ")
    year = int(input("choose year: "))
    januar = 31
    februar = isItLeapYear(year)
    march = 31
    april = 30
    may = 31
    june = 30
    july = 31
    august = 31
    september = 30
    october = 31
    november = 30
    december = 31
    countMonths = [januar , februar ,march , april , may , june , july , august , september , october , november , december ]
    monthsNames = ['januar' , 'februar' ,'march' , 'april' , 'may' , 'june' , 'july' , 'august' , 'september' , 'october' , 'november' , 'december' ]
    
    
    # Calculate the number of days in years and the number of days in the last month.
    daysInYears = yearsToDays(year)
    daysInLastMonth = monthToDays(month,year, countMonths, monthsNames)
    
    # Print the calendar.
    printCalendar((daysInYears+daysInLastMonth)%7,month,year,countMonths, monthsNames)
    
    
def main():
    calendar()
main()