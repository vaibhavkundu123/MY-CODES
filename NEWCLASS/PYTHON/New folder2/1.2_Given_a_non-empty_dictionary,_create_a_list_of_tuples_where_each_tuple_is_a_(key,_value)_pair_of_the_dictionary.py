n = int(input("Enter the number of key-value pairs: "))
user_dict = {}
for _ in range(n):
    key = input("Enter key: ")
    value = input("Enter value: ")
    user_dict[key] = value

list_of_tuples = []
for key, value in user_dict.items():
    list_of_tuples.append((key, value))

print("List of tuples:", list_of_tuples)