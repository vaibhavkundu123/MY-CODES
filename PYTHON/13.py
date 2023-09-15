a = int(input("Enter 1st number: "))
b = int(input("Enter 2nd number: "))

if(a<b):
    divisor = a
    dividend = b
else:
    divisor = b
    dividend = a

while(divisor > 0):
    remainder = dividend % divisor
    dividend = divisor
    divisor = remainder

print("GCD =", dividend)
