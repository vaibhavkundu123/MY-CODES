# Function to calculate the area of a circle
calculate_circle_area() {
    echo -n "Enter the radius of the circle: "
    read -r radius
    pi=3.14
    area=$(echo "$pi * $radius * $radius" | bc)
    echo "The area of the circle is: $area"
}

# Function to calculate the area of a rectangle
calculate_rectangle_area() {
    echo -n "Enter the length of the rectangle: "
    read -r length
    echo -n "Enter the width of the rectangle: "
    read -r width
    area=$(echo "$length * $width" | bc)
    echo "The area of the rectangle is: $area"
}

# Function to calculate the area of a triangle
calculate_triangle_area() {
    echo -n "Enter the base of the triangle: "
    read -r base
    echo -n "Enter the height of the triangle: "
    read -r height
    area=$(echo "0.5 * $base * $height" | bc)
    echo "The area of the triangle is: $area"
}

# Main menu
while true; do
    echo
    echo "Choose an option:"
    echo "1. Calculate the area of a circle"
    echo "2. Calculate the area of a rectangle"
    echo "3. Calculate the area of a triangle"
    echo "4. Exit"
    echo
    read -r choice

    case $choice in
        1)
            calculate_circle_area
            ;;
        2)
            calculate_rectangle_area
            ;;
        3)
            calculate_triangle_area
            ;;
        4)
            echo "Exiting the program."
            exit 0
            ;;
        *)
            echo "Invalid option. Please choose a valid option."
            ;;
    esac
done

