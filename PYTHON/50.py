from functools import reduce
print("Maximum value in the list:", reduce(lambda x, y: x if x > y else y, [int(x) for x in input("Enter a list of numbers separated by spaces: ").split()]))
