def octal_to_string(octal):
    permission_map = {
        '0': '---',
        '1': '--x',
        '2': '-w-',
        '3': '-wx',
        '4': 'r--',
        '5': 'r-x',
        '6': 'rw-',
        '7': 'rwx'
    }

    octal_str = str(octal)

    permission_str = ''

    for digit in octal_str:
        permission_str += permission_map[digit]
    return permission_str


octal_permissions = [755, 750, 642]

for octal in octal_permissions:
    print(f"{octal} {octal_to_string(octal)}")