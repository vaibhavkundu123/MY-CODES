sentence = input("Enter a sentence: ").lower()
word = input("Enter the word: ").lower()

count = 0

for i in range(len(sentence)):
    if sentence[i : i + len(word)] == word:
        count += 1

print(f"The word '{word}' appears {count} times in the sentence.")
