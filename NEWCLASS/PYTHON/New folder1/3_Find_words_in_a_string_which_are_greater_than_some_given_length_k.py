input_string = input("Enter a string: ").lower()
k = int(input("Enter the length k: "))

words = input_string.split()
long_words = []

for word in words:
    if len(word) > k:
        long_words.append(word)

print(long_words)
