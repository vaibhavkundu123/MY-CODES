string1 = input("Enter a string1: ").lower()
string2 = input("Enter a string2: ").lower()

char_counts = {}

for char in string1:
    char_counts[char] = char_counts.get(char, 0) + 1

for char in string2:
    char_counts[char] -= 1

is_anagram = all(count == 0 for count in char_counts.values())

print(is_anagram)
