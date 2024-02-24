list1 = [int(x) for x in input("Enter the elements of the first list separated by spaces: ").split()]

list2 = [int(x) for x in input("Enter the elements of the second list separated by spaces: ").split()]

result = list1
for element in list2:
    if element not in result:
        result.append(element)

print(f"Union List = {result}")


