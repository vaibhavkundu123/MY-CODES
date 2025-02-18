set_1 = set(input("Enter the elements of set 1 (spaces separated): ").split())
set_2 = set(input("Enter the elements of set 2 (spaces separated): ").split())

common_elements = set_1.intersection(set_2)

is_subset = common_elements == set_1

print("Is set_1 a subset of set_2?", is_subset)