"""
Student: orel twito
Assignment no. 4
Program: minesweeper.py
"""
import random


# Function to check if the player has won.
def cheking_win(dic,numbombs):
    counter = numbombs
    for (k, v) in dic:
        if dic[k,v][0] == 1: 
            counter +=1 
    if counter == len(dic):
        return 1
    else:
        return 0
    
    
# Function to expose a cell and its neighbors recursively.
def Expose(dic,x,y):
    if (x,y) in dic and dic[x,y][0] != 1:
        dic[x,y][0] = 1
        if dic[x,y][1] != 0:
            return dic
        
        else:
            Expose(dic, x-1, y-1)
            Expose(dic, x-1, y)
            Expose(dic, x-1, y+1)
            Expose(dic, x, y-1)
            Expose(dic, x, y+1)
            Expose(dic, x+1, y-1)
            Expose(dic, x+1, y)
            Expose(dic, x+1, y+1)
        return dic


def Quard(dic):
    x, y = input("Enter qurd: ").split()
    while True:
        if (int(x),int(y)) not in dic:
           print('quard not on the board')
           x, y = input("Enter qurd: ").split()
        else: 
            return(int(x),int(y))
            break
            
        
# Function to initialize the game board.
def di(size,numbombs):
    dic = {(i,j): [0,0] for i in range(1,size+1) for j in range(1,size+1)}
    counter = 0
    temp = []
    while counter < numbombs:
        x = random.randint(1, size)
        y = random.randint(1, size)
        c = [x,y]
        if c not in temp:
            temp.append(c)
            counter += 1
            dic[x,y][1] = "*"
    for (i,j) in dic:
        if dic[i,j][1] == "*":
            for q in range(i-1,i+2):
                for w in range(j-1,j+2):
                    if (q,w) in dic and dic[q,w][1] != "*": 
                        dic[q,w][1] += 1
    return dic
        
# Function to display the game board.
def Display(size,dic):
    l = "  +"
    for i in range(size):
        temp = ("---+")                                 
        l +=temp                                    
    print(l)
    col = []
    c = [f"  {i}" for i in range(1,size+1)]
    c = " ".join(c)
    for i in range(1,size+1):
        col.append(f"{i} |")
        for current in range(1,size+1):
            if dic[i,current][0] == 1:
                col.append(f"{dic[i,current][1]} |")
            else:
                col.append("  |")
        print(*col)
        col = []
        print(l)   
    print(f"  {c}")
    
    
# Function to play the Minesweeper game.
def minesweeper():
    print("Hi and welcome to minesweeper")
    print("please enter the size you want to play")
    while True:
        size = int(input("the size to Square board can be 2-9: "))
        if size < 10 and size > 1:
            break
    while True:
        numbombs = int(input(f"choose how many bombs you want in the board, can be 1-{2*size}: "))
        if numbombs < 2*size+1 and numbombs > 0:
            break
    dic = di(size,numbombs)
    Display(size,dic)
    while True:
        try:
            x,y = (int(num) for num in input("enter quard: ").split())
            if (x,y) in dic:
                if dic[x,y][0] == 1:
                    print("this quard allready exposed")
                    continue
                if dic[x,y][1] == "*":
                    for (k,v) in dic:
                        if dic[k,v][1] == "*":
                            dic[k,v][0] = 1
                    Display(size, dic)
                    print("you Lose")
                    print(chr(4), "maybe next time", chr(4))
                    break
                else:
                    dic = Expose(dic,x,y)
                    if cheking_win(dic,numbombs) == 1:
                        Display(size, dic)
                        print(chr(3),"You win my friend", chr(3))
                        break
                    Display(size, dic)
                    continue
                
            else:
                print("what you enter not in the board, please choose again")

        except:
            print("what you enter not in the board, please choose again")
def main():
    minesweeper()
main() 