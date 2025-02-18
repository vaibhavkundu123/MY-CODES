n = int(input("Enter the number of key-value pairs: "))
user_dict = {}
for _ in range(n):
    key = input("Enter key: ")
    value = input("Enter value: ")
    user_dict[key] = value

result_list = []

for key in user_dict.keys():
    result_list.append(key)

for value in user_dict.values():
    result_list.append(value)

print("Result list:", result_list)