# Create record.txt with the provided student data
cat <<EOL > record.txt
Roll Name Dept Gender
12 Amit Das CSE M
20 Paramita Sen cse F
14 Soumya Paul CSE M
11 Bidisha Nandy CSE F
15 Soumik Dey it M
13 Ajit kumar CSE M
21 Satyam Kumar IT M
15 Ipshita Das ECE F
EOL

# i) Display the record of students belong to the CSE dept.
echo "Students in CSE Department:"
grep -i ' CSE ' record.txt
echo

# ii) Count the number of students in CSE dept.
count=$(grep -ic ' CSE ' record.txt)
echo "Number of students in CSE Dept: $count"
echo

# iii) Display the record of students belong to the IT dept.
echo "Students in IT Department:"
grep -i ' IT ' record.txt
echo

# iv) Display the record of students those are not in the CSE dept.
echo "Students not in CSE Department:"
echo "Roll Name Dept Gender"  # Print header
grep -vi ' CSE ' record.txt | sed '1d'  # Remove the header line from the output
echo

# v) Count the number of girl students in CSE dept.
girl_count=$(grep -i ' CSE ' record.txt | grep -c -w 'F')
echo "Number of girl students in CSE Dept: $girl_count"
echo

# vi) Display the record of girl students belong to the CSE dept.
echo "Girl students in CSE Department:"
grep -i ' CSE ' record.txt | grep 'F'
