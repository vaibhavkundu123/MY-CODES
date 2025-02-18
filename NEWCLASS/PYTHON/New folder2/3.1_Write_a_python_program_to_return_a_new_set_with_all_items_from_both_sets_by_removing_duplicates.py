set_1 = set(input("Enter the elements of set 1 (spaces separated): ").split())
set_2 = set(input("Enter the elements of set 2 (spaces separated): ").split())

new_set = set_1.union(set_2)

print("The new set is:", new_set)