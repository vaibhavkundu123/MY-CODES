input_list = input("Enter the list (separated by commas): ").split(", ")

output_list = []

for num in input_list:
    if num.endswith(".cpp"):
        output_list.append(num[:-4] + ".h")
    else:
        output_list.append(num)

print(output_list)