import random


class NumberBelowThresholdError(Exception):
    pass


try:
    num = random.random()

    print(f"Generated number: {num}")

    if num < 0.5:
        raise NumberBelowThresholdError("Number is below 0.5")

except NumberBelowThresholdError as e:
    print(f"Error: {e}")
