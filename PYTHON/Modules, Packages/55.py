import random

start = int(input("Enter the start of the range: "))
end = int(input("Enter the end of the range: "))
size = int(input("Enter the size of the list: "))

# numbers = [random.randint(start, end) for _ in range(size)]

numbers = []
for _ in range(size):
    numbers.append(random.randint(start, end))

print(f"Original list: {numbers}")

random.shuffle(numbers)

print(f"Shuffled list: {numbers}")
