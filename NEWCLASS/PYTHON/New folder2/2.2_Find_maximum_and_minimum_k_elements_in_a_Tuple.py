tup = tuple(map(int, input("Enter the elements of the tuple (spaces separated): ").split()))

k = int(input("Enter the value of k: "))

sorted_tup = sorted(tup)

min_k_elements = sorted_tup[:k]

max_k_elements = sorted_tup[-k:]

print(f"The minimum {k} elements are: {min_k_elements}")
print(f"The maximum {k} elements are: {max_k_elements}")