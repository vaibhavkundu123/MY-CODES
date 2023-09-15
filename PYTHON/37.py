numbers = tuple(int(x) for x in input("Enter the elements of the tuple separated by spaces: ").split())

frequency = {}
for number in numbers:
    if number in frequency:
        frequency[number] += 1
    else:
        frequency[number] = 1

for key, value in frequency.items():
    print(f"{key}: {value}")
