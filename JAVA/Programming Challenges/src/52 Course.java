//  Design a Course class.
//• Instance variables: courseName, enrolledStudents.
//• Static variable: maxCapacity, the maximum number of students for any course.
//• Instance methods: enrollStudent(String studentName), unenrollStudent(String studentName).
//• Static method: setMaxCapacity(int capacity), to set the maximum capacity for courses.

class Course {
    static int maxCapacity = 100;
    String courseName;
    int enrollments;

    String[] enrolledStudents;

    Course(String courseName) {
        this.courseName = courseName;
        this.enrollments = 0;
        this.enrolledStudents = new String[maxCapacity];
    }

    static void setMaxCapacity(int maxCapacity) {
        Course.maxCapacity = maxCapacity;
    }

    void enrollStudent(String studentName) {
        enrolledStudents[enrollments] = studentName;
        enrollments++;
        System.out.println("\nStudent " + studentName + " enrolled in " + courseName);
    }

    void unenrollStudent(String studentName) {
        int studentIndex = -1;

        for (int i = 0; i < enrollments; i++) {
            if (enrolledStudents[i].equals(studentName)) {
                studentIndex = i;
                break;
            }
        }

        if (studentIndex != -1) {
            for (int i = studentIndex; i < enrollments - 1; i++) {
                enrolledStudents[i] = enrolledStudents[i + 1];
            }

            enrollments--;
            enrolledStudents[enrollments] = null;

            System.out.println("\nStudent " + studentName + " removed from " + courseName);
        } else {
            System.out.println("\nStudent " + studentName + " not found in the course");
        }
    }

    void printEnrolledStudentsName() {
        System.out.println("\nEnrolled Students in " + courseName + " are:");
        for (String student : enrolledStudents) {
            if (student != null) {
                System.out.println(student);
            }
        }
    }

    public static void main(String[] args) {
        Course course = new Course("Introduction to Java");

        course.enrollStudent("Alice");
        course.enrollStudent("Bob");
        course.enrollStudent("Charlie");
        course.enrollStudent("David");

        course.unenrollStudent("Bob");

        course.printEnrolledStudentsName();
    }
}
