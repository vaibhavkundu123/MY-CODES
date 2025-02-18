myset = set(input("Enter the initial set elements (spaces separated): ").split())
print("Initial set:", myset)

n = input("Enter the element to remove: ")
myset.remove(n)

print("Updated set:", myset)