# Prompt the user for the first number
echo "Enter the first number:"
read num1

# Prompt the user for the second number
echo "Enter the second number:"
read num2

# Prompt the user for the third number
echo "Enter the third number:"
read num3

# Determine the largest number
if [ "$num1" -ge "$num2" ] && [ "$num1" -ge "$num3" ]; then
    largest=$num1
elif [ "$num2" -ge "$num1" ] && [ "$num2" -ge "$num3" ]; then
    largest=$num2
else
    largest=$num3
fi

# Print the largest number
echo "The largest number among $num1, $num2, and $num3 is: $largest"
