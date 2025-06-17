# -*- coding: utf-8 -*-
"""
Created on Tue Mar  9 12:43:52 2021
@author: Sumon

#Variables and Values, 
#Built-in Data Types, 
#Type Casting, 
#Boolean Expression Evaluation, 
#Operators, Expression Evaluation.
"""

import sys
print(sys.version);  

print("hello");       #By defult \n At the end of the line

if 5 > 2:       # : is define begining of Block Test for Indentation
    print("Five is greater than two!")
if 5 > 2:
 print("Five is greater than two!")
#datatype
 
 
x =4
y = "Sumon"
z=3+5j
p=4.5
q=True
x = int(4)
y = str("Sumon")
z= complex(3,5)

print(x,end="\n")
print(y,end="\n")
print(z,end="\n")
print("Name",y,"Id",x,sep=":",end="\n")
print(type(x))
print(type(y))
print(type(z))


x=1233333333
print(x)
print(sys.getsizeof(x))   #Size automatically extended by 4

print(0b101) #binary Number
print(0o10)  #Octal Number
print(0xF)   #Hexadecimal Number



a=-5 % 3                     #[  a%b= a-(floor(a/b)*b)  ] -5-(-2*3)
b=-5//3                      # floor division
print(a,"\n",b,sep="")   

x="Sumon"                   #in operator
a= "S" in x                 #S present in String or not
print(a)
      
x=2                        #is operator
y=2
print(x is y)              #both are same object

x=~4
print(x) #1's Complement

   
x = - 3 + 4 * 5 - 6 ;print( x,end="\n") #11
x = 3 + 4 % 5 - 6 ; print( x,end="\n")  #1
x = - 3 * 4 % 6 / 5; print( x,end="\n") #0.0
x = ( 7 + 6 ) % 5 / 2; print( x,end="\n")  #1.5

x=2; y=4; z=4
x *= 3 + 2 ; print( x,end="\n") #10
x *= y; print( x,end="\n")      #40
x = y == z ; print( x,end="\n") #true
x=y=z*4; print(x,end="\n") #16

x = 2 ; y = 1 ; z = 0 ;
print(x!=0 and y!=0 or z!=0 ,end="\n") #true 
print(x!=0 or not y!=0 and z!=0 , end="\n")#true 
x = 3 ; y=z=4 
print(not(y>=x),end="\n")    #false
print( z >= y and y >= x,end="\n")  #true

x = 3 ; y = 2 ; z = 1 
print(x | y & z)   #3 1st & then |
print( x | y & ~z) #3 1st & then |
print( x ^ y & ~z) #1 1st & then ^
y <<= 3 ; print(y) ; #16
y >>= 3 ; print(y) ; #2


#Swap to number
x,y=2,3  # multi variable assignment
print("Before Swapping",x,y)
t=x;x=y;y=t      #with third variable
print("After Swapping",x,y)

x,y=2,3
print("Before Swapping",x,y)
x=x+y;y=x-y;x=x-y      #with third variable
print("After Swapping",x,y)

x,y=2,3
print("Before Swapping",x,y)
x,y=y,x       #with multi variable assignment
print("Before Swapping",x,y)

#Distance between two points (x1,y1) and (x2,y2)
import math
x1,y1=2,4
x2,y2=6,6
dist=math.sqrt(math.pow(x2-x1,2)+math.pow(y2-y1,2))
print("Distance : ",dist)

#Find out the Area of a Circle.
import math
redius=4
area=math.pi*redius*redius
print(area)

#convert temperature from Fahrenheit to Celsius and vice versa
f=41
c=((f-32)/9)*5
print(c)

f=(c*9/5)+32
print(f)

