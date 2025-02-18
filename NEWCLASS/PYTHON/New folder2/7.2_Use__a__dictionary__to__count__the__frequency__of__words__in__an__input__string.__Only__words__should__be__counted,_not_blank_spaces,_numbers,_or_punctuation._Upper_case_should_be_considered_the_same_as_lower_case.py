import re

sentence = input("Enter a sentence: ")

cleaned_text = re.sub(r'[^a-zA-Z\s]', '', sentence)

words = cleaned_text.lower().split()

word_count = {}

for word in words:
    if word:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1

print(word_count)