input_filename = input("Enter the input filename: ")
output_filename = input("Enter the output filename: ")

with open(input_filename, 'r') as infile, open(output_filename, 'w') as outfile:
    for line in infile:
        if '#' in line:
            # split the line into two parts: before and after the comment symbol
            line, comment = line.split('#', 1)
        # write the line (without trailing spaces) to the output file
        outfile.write(line.rstrip() + '\n')
