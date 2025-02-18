n = int(input("Enter the number of key-value pairs: "))
user_dict = {}
for _ in range(n):
    key = input("Enter key: ")
    value = input("Enter value: ")
    user_dict[key] = value

# (i) by keys

keys = []
for key in user_dict.keys():
    keys.append(key)
keys.sort()
print("Keys in sorted order: ", keys)

# (ii) by values

values = []
for value in user_dict.values():
    values.append(value)
values.sort()
print("Values in sorted order: ", values)