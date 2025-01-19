echo "Enter the number of inputs:"
read num_inputs

# Prompt the user to enter five city names
for ((i=0; i<num_inputs; i++)); do
    echo "Enter city name $((i + 1)):"
    read cities[i]
done

# Print the city names in ascending order
echo "Cities in ascending order:"
for city in "${cities[@]}"; do
    echo "$city"
done | sort

# Print the city names in descending order
echo "Cities in descending order:"
for city in "${cities[@]}"; do
    echo "$city"
done | sort -r

