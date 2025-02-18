sentence = input("Enter a sentence: ")

words = sentence.split()

unique_words = set()

result = []

for word in words:
    if word not in unique_words:
        unique_words.add(word)
        result.append(word)

result = ' '.join(result)


print("Sentence without duplicate words:", result)