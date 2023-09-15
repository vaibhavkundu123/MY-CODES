x = int(input("Enter the value of x: "))
y = int(input("Enter the value of y: "))

print(f"Before swapping: x = {x} , y = {y}")

x = x ^ y
y = x ^ y
x = x ^ y


print(f"After swapping using bitwise operators: x = {x} , y = {y}")
