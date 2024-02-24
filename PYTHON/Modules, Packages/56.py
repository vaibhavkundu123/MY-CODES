import random

start = int(input("Enter the start of the range: "))
end = int(input("Enter the end of the range: "))
size = int(input("Enter the size of the list: "))

numbers = [random.randint(start, end) for _ in range(size)]

print(f"List of random numbers: {numbers}")
