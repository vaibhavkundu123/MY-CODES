string = input("Enter a string: ").lower().replace(" ","")
#string = string.replace(" ","")

'''substrings = []

for i in range(len(string)):
    for j in range(i + 1, len(string) + 1):
        substrings.append(string[i:j])

print(substrings)'''

substrings = []

for i in range(len(string)):
  for j in range(i + 1, len(string) + 1):
    substrings.append(string[i:j])

substrings.sort(key=len)

for substring in substrings:
  print(substring)


