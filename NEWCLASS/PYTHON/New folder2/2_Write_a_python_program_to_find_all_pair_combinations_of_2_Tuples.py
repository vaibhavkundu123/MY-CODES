tuple1 = tuple(map(int, input("Enter first tuple elements (comma separated): ").split(',')))
tuple2 = tuple(map(int, input("Enter second tuple elements (comma separated): ").split(',')))

all_pairs = []

for x in tuple1:
    for y in tuple2:
        all_pairs.append((x, y))


print("\nAll possible pairs:")
for pair in all_pairs:
    print(pair)