n = int(input("Enter the number of terms: "))

first = 0
second = 1

fibonacci_series = (first, second)

for i in range(2, n):
    next_term = first + second
    fibonacci_series += (next_term,)
    first, second = second, next_term

print(fibonacci_series)