numbers = [int(x) for x in input("Enter a list of numbers, separated by spaces: ").split()]
max_num = numbers[0]
min_num = numbers[0]
for num in numbers:
    if num > max_num:
        max_num = num
    if num < min_num:
        min_num = num
print(f"Maximum {max_num}, Minimum {min_num}")
