sum = 0

first_number = 0
second_number = 1

while second_number <= 100:
    if second_number % 2 == 0:
        sum += second_number

    temp = first_number
    first_number = second_number
    second_number = temp + second_number

print(f"The sum of all the even_valued terms of the Fibonacci series upto 100 is {sum}.")
