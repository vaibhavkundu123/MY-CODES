initial_set = set(input("Enter the initial set elements (spaces separated): ").split())

elements_to_add = list(input("Enter the list of elements to add (spaces separated): ").split())

for element in elements_to_add:
    initial_set.add(element)

print("Updated set:", initial_set)