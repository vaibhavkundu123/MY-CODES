input_string = input("Enter the main string: ").lower()
sub_string = input("Enter the substring to count: ").lower()

count = 0

for i in range(len(input_string) - len(sub_string) + 1):
    if input_string[i:i + len(sub_string)] == sub_string:
        count += 1

print(f"Number of overlapping occurrences: {count}")