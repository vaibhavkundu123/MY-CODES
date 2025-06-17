# -*- coding: utf-8 -*-
"""
Created on Fri Mar 12 10:21:33 2021

@author: Sumon

if 
if else
ladder elif
nested if-else
"""

#Chek the Number is Odd or Even 
print("Enter the No :")
x=int(input())
if x % 2 ==0:
    print(x,"is a Even Number ")
else:
    print(x,"is a Odd Number ")
    


#Nested if-else and Ladder 
x=int(input())
if x > 0:
    print("Number is Positive")
    if x>=10 and x<=20:
        print("Number is in between 10 & 20")
    else:
        print("Number is not in between 10 & 20")
elif x==0:
    print("Number is Zero")
else:
    print("Number is Negetive")



#Check the Number is leap year or not
print("Enter the Year")
year=int(input())
if year%4==0 and year%100!=0 or year%400==0:
    print(year,"a Leap Year")
else:
    print(year,"Not a Leap Year")



#Roots of quadratic equation 
import cmath
import math
a=1;b=1;c=4
d=b**2-4*a*c
if d>0:
    x1=(-b+math.sqrt(d))/2*a
    x2=(-b-math.sqrt(d))/2*a
    print("Root x1=",x1,"x2=",x2)
elif d<0:
    x1=(-b+cmath.sqrt(d))/2*a
    x2=(-b-cmath.sqrt(d))/2*a
    print("Root x1=",x1,"x2=",x2)
else:
    x1=x2=-b/2*a;
    print("Root x1=",x1,"x2=",x2)



#Triangle Problems
print("Input lengths of the triangle sides: ")
x = int(input("x: "))
y = int(input("y: "))
z = int(input("z: "))
if (x + y > z) and (x + z > y) or (y + z > x) :
    if x ** 2 + y ** 2 == z ** 2 or y ** 2 + z ** 2 == x ** 2 or  x ** 2 + z ** 2 == y ** 2:
        print("Right angle triangle")
    if x == y == z:
        print("Equilateral triangle")
    elif x==y or y==z or z==x:
        print("isosceles triangle")
    else:
        print("Scalene triangle")
    # calculate the area
    s = (x + y + z) / 2
    area = (s*(s-x)*(s-y)*(s-z)) ** 0.5
    print(area)
else:
    print("triangle is Invalid") 
