x = int(input("Enter the value of x: "))
y = int(input("Enter the value of y: "))
z = int(input("Enter the value of z: "))

print(f"Before swapping: x = {x} , y = {y} , z = {z}")

x , y , z = y , z, x

print(f"After swapping: x = {x} , y = {y} , z = {z}")
