"""
Student: orel twito
Assignment no. 4
Program: matrix.py
"""

# Function to print a matrix.
def print_matrix(Result):
    for j in Result:
        print(*j)

# Function to add two matrices.
def add_matrix(At,B):
    temp = []
    c = []
    for i in range(len(At)):
        for j in range(len(At[0])):
            temp.append(At[i][j]+B[i][j])   
        c.append(temp)
        temp = []
    return(c)

# Function to transpose a matrix using nested loops.
def transpose(a):
    temp = []
    for c in a: 
        for j in c:
            temp.append(j)
    temp2 = []
    at = []
    for c in range(len(a[0])):
        temp2.append(temp[c::len(a[0])])
        at.extend(temp2)
        temp2 = []

    return(at)


# Function to transpose a matrix using list comprehension.
def transposeComprehension(A):
    at = [[A[j][i] for j in range(len(A))] for i in range(len(A[0])) ]
    return(at)


def main():           
    while True:
        filename = input("choose filename: ")
        try:
            file = open(filename,'r')
            break
        except FileNotFoundError as error:
            print(error)
            
    A = []
    B = []
    flag = False
    
    for j in file:
        if j[0] == "B":
            flag = True
            continue
        if j[0] == 'A':
            flag = False
            continue
        temp = j.split()
        for i in range(len(temp)):
            temp[i] = int(temp[i])
        if flag:
            B.append(temp.copy())
        else:
            A.append(temp.copy())
    file.close()  
    
    At = transposeComprehension(A)
#    At = transpose(A)
    Result = add_matrix(At,B)
    print_matrix(Result)
main()

