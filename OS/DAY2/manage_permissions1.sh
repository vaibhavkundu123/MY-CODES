# Prompt the user for the file name
echo "Enter the file name to create:"
read -r file_name

# Create the file
touch "$file_name"

# Display the default file permissions
echo "Default file permissions:"
ls -l "$file_name"

# Prompt the user for the option to perform
echo "1. User: all permissions, Group: read and write, Others: read"
echo "2. User: all permissions"
echo "3. User, Group, and Others: all permissions"
echo "Select an option to change file permissions:"
read -r option

# Perform actions based on the selected option
case "$option" in
    1)
        # Change permissions: User: rwx, Group: rw-, Others: r--
        chmod 764 "$file_name"
        echo "Permissions set to: User (rwx), Group (rw-), Others (r--)"
        ;;
    2)
        # Change permissions: User: rwx, Group and Others: no permissions
        chmod 700 "$file_name"
        echo "Permissions set to: User (rwx), Group (---), Others (---)"
        ;;
    3)
        # Change permissions: User, Group, and Others: rwx
        chmod 777 "$file_name"
        echo "Permissions set to: User (rwx), Group (rwx), Others (rwx)"
        ;;
    *)
        echo "Invalid option selected."
        exit 1
        ;;
esac

# Display the updated file permissions
echo "Updated file permissions:"
ls -l "$file_name"
