student_data = {
    "roll": 5,
    "Name": "Ananya",
    "marks": [79, 88,  92]
}

# (i) Update the dictionary with an added item of the total of the student’s marks.

student_data["total"] = sum(student_data["marks"])
print(student_data)
del student_data["total"]

# (ii) Update the dictionary with an added entry of the total of the student’s marks in the list.

student_data["marks"].append(sum(student_data["marks"]))
print(student_data)
student_data["marks"].pop()

# (iii) Update the dictionary with the students’ marks list replaced by the total marks of the student.

student_data["marks"] = sum(student_data["marks"])
print(student_data)
