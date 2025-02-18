input_list = input("Enter the list (separated by commas): ").split(", ")

for i in range(len(input_list)):
    input_list[i] = int(input_list[i])

i = 0

for i in range(len(input_list)):
    sum_of_digits = 0
    for digit in str(input_list[i]):
        sum_of_digits += int(digit)
    input_list[i] = sum_of_digits

print(input_list)