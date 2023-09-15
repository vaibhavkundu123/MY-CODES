numbers = tuple(int(x) for x in input("Enter the elements of the tuple separated by spaces: ").split())

total = 0
for number in numbers:
    total += number

mean = total / len(numbers)

print(f"Mean = {mean}")
