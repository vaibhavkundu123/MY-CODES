import random

try:
    for i in range(1, 11):
        print(random.randint(1, 100))

    raise StopIteration

except StopIteration:
    print("\nStopIteration exception raised. Exiting the program.")
