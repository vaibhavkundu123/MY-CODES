input_string = input("Enter a string: ")

vowels = 'aeiou'

sequences = []
current_sequence = ''

for char in input_string:
    if char.lower() not in vowels:
        current_sequence += char
    else:
        if current_sequence:
            sequences.append(current_sequence)
        current_sequence = ''

if current_sequence:
    sequences.append(current_sequence)

if sequences:
    longest_length = 0
    for sequence in sequences:
        if len(sequence) > longest_length:
            longest_length = len(sequence)
    
    for sequence in sequences:
        if len(sequence) == longest_length:
            print(f"Longest consonant substring: {sequence}")    
else:
    print("No consonant sequences found")
