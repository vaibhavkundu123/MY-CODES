original_tuple = tuple(int(x) for x in input("Enter the elements of the original tuple separated by spaces: ").split())

new_elements = tuple(int(x) for x in input("Enter the elements of the new tuple separated by spaces: ").split())

new_tuple = original_tuple + new_elements

print(f"New Tuple = {new_tuple}")
