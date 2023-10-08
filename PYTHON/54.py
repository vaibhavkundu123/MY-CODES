""" import random
import statistics

numbers = [random.randint(1, 10) for _ in range(10)]

mean = statistics.mean(numbers)

median = statistics.median(numbers)

std_dev = statistics.stdev(numbers)

print(f"Numbers: {numbers}")
print(f"Mean: {mean}")
print(f"Median: {median}")
print(f"Standard Deviation: {std_dev}") """

""" import random
import math

numbers = [random.randint(1, 10) for _ in range(10)]

mean = sum(numbers) / len(numbers)

numbers.sort()
if len(numbers) % 2 == 0:
    median = (numbers[len(numbers)//2] + numbers[len(numbers)//2 - 1])/2
else:
    median = numbers[len(numbers)//2]

variance = sum((n - mean) ** 2 for n in numbers) / len(numbers)
std_dev = math.sqrt(variance)

print(f"Numbers: {numbers}")
print(f"Mean: {mean}")
print(f"Median: {median}")
print(f"Standard Deviation: {std_dev}") """

import random, math
numbers = [random.randint(1, 10) for i in range(10)]
mean = sum(numbers) / len(numbers)
numbers.sort()
median = numbers[len(numbers)//2] if len(numbers) % 2 != 0 else sum(numbers[len(numbers)//2-1:len(numbers)//2+1]) / 2
std_dev = math.sqrt(sum((n - mean) ** 2 for n in numbers) / len(numbers))
print(f"Numbers: {numbers}\nMean: {mean}\nMedian: {median}\nStandard Deviation: {std_dev}")
