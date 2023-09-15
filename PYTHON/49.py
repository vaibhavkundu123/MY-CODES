numbers = [int(x) for x in input("Enter a list of numbers separated by spaces: ").split()]
even_numbers = list(filter(lambda x: x % 2 == 0, numbers))
print("Even numbers in the list:", even_numbers)
