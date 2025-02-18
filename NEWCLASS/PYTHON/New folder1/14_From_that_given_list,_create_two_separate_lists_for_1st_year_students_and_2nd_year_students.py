input_list = input("Enter the list (separated by commas): ").split(", ")

output_list_1 = []
output_list_2 = []

for element in input_list:
    if element.startswith("21"):
        output_list_1.append(element)
    else:
        output_list_2.append(element)

print(output_list_1, output_list_2)