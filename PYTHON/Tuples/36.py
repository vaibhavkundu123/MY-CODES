numbers = tuple(int(x) for x in input("Enter the elements of the tuple separated by spaces: ").split())

unique_elements = []
duplicate_elements = []

for number in numbers:
    if numbers.count(number) == 1:
        unique_elements.append(number)
    elif number not in duplicate_elements:
        duplicate_elements.append(number)

print("Unique elements: ", unique_elements)
print("Duplicate elements: ", duplicate_elements)
