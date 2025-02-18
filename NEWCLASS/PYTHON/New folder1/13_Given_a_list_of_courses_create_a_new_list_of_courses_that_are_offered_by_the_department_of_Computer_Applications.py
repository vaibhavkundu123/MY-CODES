input_list = input("Enter the list (separated by commas): ").split(", ")

output_list = []

for element in input_list:
    if element.startswith("MCA"):
        output_list.append(element)

print(output_list)