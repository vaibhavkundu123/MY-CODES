numbers = map(int, input("Enter numbers separated by space: ").split())
result = []

for num in numbers:
    result.append((num, num**3))

print(result)
