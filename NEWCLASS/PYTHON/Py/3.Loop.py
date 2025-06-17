# -*- coding: utf-8 -*-
"""
Created on Mon Mar 15 09:38:37 2021

@author: Sumon
Loop Problems
"""

#Factorial of a Number
i=1
fact=1
print("Enter the Number")
n=int(input())
while i<=n:
    fact=fact*i
    i=i+1
print(fact)


#Series of Natural Number 1+2+3+4............n
i=1
sum=0
print("Enter the Number")
n=int(input())
for i in range(1,n+1):
    sum+=i
print(sum)


# Series of Odd Number 1+3+5+7............2n-1
i=1
sum=0
print("Enter the Number")
n=int(input())
for i in range(1,n+1):   # for i in range(1,2*(n+1)-1,2):
    sum=sum+(2*i-1)
print(sum)



#Series of  1^1/1!-3^2/2!+5^3/3!-7^4/4!............((2n-1)^n * (-1)^n-1) / n!
import math
i=1
sum=0
print("Enter the Number")
n=int(input())
for i in range(1,n+1):   # for i in range(1,2*(n+1)-1,2):
    sum=sum+(pow((2*i-1),i)*pow(-1,i-1))/math.factorial(i)
print(sum)



# Sin Series (With using N th Term ) x −  x^3/3!  +  x^5/5!  −  ... 
import math 
i = 1
sum = 0
print("Enter the Degree : ")
x = int(input())
print("Enter the nth Number : ")
n = int(input())
x =(x*math.pi)/180
for i in range(1,n+1):   # for i in range(1,2*(n+1)-1,2):
    sum=sum+(pow(x,(2*i-1))*pow(-1,i-1))/math.factorial(2*i-1)
print(sum)



# Sin Series (Without using Nth Term ) x −  x^3/3!  +  x^5/5!  −  ... 
import math
i = 1
sum1 = 0
print("Enter the Degree : ")
x = int(input())
x =(x*math.pi)/180
term = x
sum1 = x
while True:  
    term =(term*(-1)*x*x)/(2*i*(2*i+1))
    sum1 = sum1 + term
    i = i + 1  
    if(math.fabs(term)<0.000001):  
        break 
print(sum1)


# Check the Number is Prime or Not
import math
n=17
c=0
for i in range(2,(int(math.sqrt(n)))+1):
    if n % i == 0:
        c=c+1
        break
if c == 0:
    print(n,"is a Prime No")
else:
    print(n,"is not a Prime No")
    

# Prime No Upto Input N
n=17
for i in range(1, n+1):
    c = 0
    for j in range(2,i):   #(int)(math.sqrt(i))+1
        if i % j == 0:
            c=c+1
    if c ==0 and i>1:
        print(i)

"""
Square of 12 is 144. 21, which is the reverse of 12 has a square 441, 
which is same as the reverse of 144. Write a program to find out all 
such nos. in the range 10 to 100.
"""


for number in range(10,101):
    n=number
    sn=n*n                          #Sqr of n 144
    
    rvn=0
    while int(n):
        r=n%10
        rvn=rvn*10+r;               #Reverse of n 21
        n=int(n/10)
    sqrrvn=rvn*rvn                  #Sqr of Reverse n 441
    
    rvsn=0
    while int(sqrrvn):
        r=sqrrvn%10
        rvsn=rvsn*10+r;             #Reverse of sqrt(n)
        sqrrvn=int(sqrrvn/10)
    
    if sn==rvsn:
        print(number)


#Star Pattern 
n=5
for i in range(1,n+1):
    for j in range(1,n+1):
        if i<=j:
            print ("*",end="")
        else:
            print (" ",end="")
    print()
