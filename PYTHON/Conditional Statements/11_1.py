n = int(input("Enter number of rows: "))
number = 1
for i in range(n):
    for j in range(i):
        print(number, end=',')
        number += 1
    print(number, "\n")
    number += 1
   
    
