# Prompt the user for the number of inputs
echo "Enter the number of inputs:"
read num_inputs

# Initialize an array
echo "Enter the array elements"
for ((i = 0; i < num_inputs; i++)); do
    echo "Enter number $((i + 1)):" 
    read numbers[i]
done

# Implement bubble sort algorithm
for ((i = 0; i < num_inputs-1; i++)); do
    for ((j = 0; j < num_inputs-i-1; j++)); do
        if [ "${numbers[j]}" -gt "${numbers[j+1]}" ]; then
            # Swap
            temp="${numbers[j]}"
            numbers[j]="${numbers[j+1]}"
            numbers[j+1]="$temp"
        fi
    done
done

# Print the sorted array
echo "Numbers in ascending order: ${numbers[@]}"
