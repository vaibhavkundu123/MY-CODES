input_list = input("Enter the list (separated by commas): ").split(", ")
input_element = input("Enter the element: ")

for element in input_list:
    if element == input_element:
        input_list.remove(element)
        input_list.append(input_element)

print(input_list)