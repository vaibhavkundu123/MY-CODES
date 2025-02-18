numbers = tuple(map(int, input("Enter the numbers (spaces separated): ").split()))

largest = max(numbers)
smallest = min(numbers)
second_largest = None
second_smallest = None

for num in numbers:
    if num != largest:
        if second_largest is None or num > second_largest:
            second_largest = num
    if num != smallest:
        if second_smallest is None or num < second_smallest:
            second_smallest = num

print("The second largest number is:", second_largest)
print("The second smallest number is:", second_smallest)