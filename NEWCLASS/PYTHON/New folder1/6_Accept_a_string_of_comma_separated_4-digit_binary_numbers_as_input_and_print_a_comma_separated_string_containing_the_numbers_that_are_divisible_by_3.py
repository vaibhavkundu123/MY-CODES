input_string = input("Enter a string: ")

binary_numbers = input_string.split(", ")

divisible_by_3 = []

for num in binary_numbers:
    if int(num, 2) % 3 == 0:
        divisible_by_3.append(num)

# Join the filtered numbers into a comma-separated string
result = ", ".join(divisible_by_3)

print(result)
