input_list = input("Enter a list (separated by commas): ").split(", ")

pairs = []

for i in range(len(input_list) - 1):
    pair = (input_list[i], input_list[i + 1])
    pairs.append(pair)

print(pairs)