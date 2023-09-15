list1 = [int(x) for x in input("Enter the elements of the first list separated by spaces: ").split()]

list2 = [int(x) for x in input("Enter the elements of the second list separated by spaces: ").split()]

result = [x for x in list1] + [x for x in list2]

print(f"Concatenated List = {result}")
