vowels = {'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0}
sentence = input("Enter a sentence: ").lower()

for letter in sentence:
    if letter in vowels:
        vowels[letter] += 1

for vowel, count in vowels.items():
    print(f"Count of - {vowel} = {count}")