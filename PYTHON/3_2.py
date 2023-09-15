# Without using a third variable

x = int(input("Enter the value of x: "))
y = int(input("Enter the value of y: "))

print(f"Before swapping: x = {x} , y = {y}")

x , y = y , x

print(f"After swapping without using a third variable: x = {x} , y = {y}")
