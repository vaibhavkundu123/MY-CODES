def unique(l):
    return [i for i in l if l.count(i) == 1]

l = input("Enter the elements separated by spaces: ").lower().split()
print(f"Unique Elements: {unique(l)}")
