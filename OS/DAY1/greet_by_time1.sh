# Get the current hour
current_hour=$(date +%H)

# Determine the appropriate greeting based on the current hour
if [ "$current_hour" -ge 0 ] && [ "$current_hour" -lt 12 ]; then
    greeting="Good Morning"
elif [ "$current_hour" -ge 12 ] && [ "$current_hour" -lt 17 ]; then
    greeting="Good Afternoon"
elif [ "$current_hour" -ge 17 ] && [ "$current_hour" -lt 21 ]; then
    greeting="Good Evening"
else
    greeting="Good Night"
fi

# Print the greeting
echo "$greeting"
