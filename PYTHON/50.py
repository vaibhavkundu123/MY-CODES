from functools import reduce

numbers = [int(x) for x in input("Enter a list of numbers separated by spaces: ").split()]
maximum_value = reduce(lambda x, y: x if x > y else y, numbers)
print("Maximum value in the list:", maximum_value)