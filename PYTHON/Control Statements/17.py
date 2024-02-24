a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))

if a <= 0 or b <=0:
    print("One of the numbers is not positive. ")
    exit()

max_number = max(a,b)

while not (max_number % a == 0 and max_number % b == 0):
    max_number += 1

print(f"The LCM of {a} and {b} is {max_number}. ")
