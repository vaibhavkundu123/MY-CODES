n = int(input("Enter the number of key-value pairs: "))
user_dict = {}
for _ in range(n):
    key = input("Enter key: ")
    value = input("Enter value: ")
    user_dict[key] = value

unique_values = set()
for value in user_dict.values():
    unique_values.add(value)

print("Unique values:", unique_values)
