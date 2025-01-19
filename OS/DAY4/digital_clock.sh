# Clear the screen
clear

# Trap the signal for CTRL+C (SIGINT) to exit the clock cleanly
trap "echo -e '\nExiting...'; exit" SIGINT

# Infinite loop to update the clock every second
while true; do
    # Clear the previous output
    clear
    
    # Get the current time and date
    current_time=$(date +"%H:%M:%S")
    current_date=$(date +"%A, %B %d, %Y")
    
    # Display the clock
    echo "-------------------------------------"
    echo "\e[31m          DIGITAL CLOCK              \e[0m"
    echo "-------------------------------------"
    echo "\e[31m              $current_time           \e[0m"
    echo "\e[31m         $current_date\e[0m"
    echo "-------------------------------------"
    echo "Press CTRL+C to exit the clock"
    
    # Wait for 1 second before updating the time
    sleep 1
done

