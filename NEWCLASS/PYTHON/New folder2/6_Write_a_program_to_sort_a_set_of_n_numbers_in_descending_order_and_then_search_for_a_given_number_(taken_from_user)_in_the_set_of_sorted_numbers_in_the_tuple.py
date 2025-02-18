numbers = tuple(map(int, input("Enter the numbers (spaces separated): ").split()))

numbers_list = list(numbers)
n = len(numbers_list)
for i in range(n):
    for j in range(0, n-i-1):
        if numbers_list[j] < numbers_list[j+1]:
            numbers_list[j], numbers_list[j+1] = numbers_list[j+1], numbers_list[j]

numbers = tuple(numbers_list)

search_number = int(input("Enter the number to search for: "))

if search_number in numbers:
    print(f"The number {search_number} is found in the sorted tuple.")
else:
    print(f"The number {search_number} is not found in the sorted tuple.")

print("Sorted numbers in descending order:", numbers)