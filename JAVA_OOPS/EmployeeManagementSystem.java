import java.io.*;
import java.util.*;

/**
 * Base class representing a generic Employee.
 */
abstract class Employee {
    protected int empCode;
    protected String empName;
    protected String empAddress;
    protected int empPhoneNumber;
    protected double basicPay;
    protected final double DA = 0.1; // Dearness Allowance
    protected final double HRA = 0.2; // House Rent Allowance

    public Employee(int empCode, String empName, String empAddress, int empPhoneNumber, double basicPay) {
        this.empCode = empCode;
        this.empName = empName;
        this.empAddress = empAddress;
        this.empPhoneNumber = empPhoneNumber;
        this.basicPay = basicPay;
    }

    /**
     * Calculates the total salary based on basic pay, DA, and HRA.
     *
     * @return Calculated salary.
     */
    public double calculateSalary() {
        return basicPay + (basicPay * DA) + (basicPay * HRA);
    }

    /**
     * Displays the common employee details.
     */
    public void displayCommonDetails() {
        System.out.println("\n----------------------------------------");
        System.out.println("Employee Code       : " + empCode);
        System.out.println("Employee Name       : " + empName);
        System.out.println("Employee Address    : " + empAddress);
        System.out.println("Employee Phone No.  : " + empPhoneNumber);
        System.out.printf("Basic Pay           : %.2f%n", basicPay);
        System.out.printf("Salary              : %.2f%n", calculateSalary());
    }

    /**
     * Returns a string representation of the employee for file storage.
     *
     * @return CSV formatted string of employee details.
     */
    public abstract String toFileString();

    /**
     * Displays additional details specific to the employee type.
     */
    public abstract void displayAdditionalDetails();
}

/**
 * Abstract class representing Teaching Employees.
 */
abstract class Teaching extends Employee {
    protected String subjectSpecialization;
    protected String designation;

    public Teaching(int empCode, String empName, String empAddress, int empPhoneNumber, double basicPay,
                   String subjectSpecialization, String designation) {
        super(empCode, empName, empAddress, empPhoneNumber, basicPay);
        this.subjectSpecialization = subjectSpecialization;
        this.designation = designation;
    }

    @Override
    public void displayAdditionalDetails() {
        System.out.println("Subject Specialization : " + subjectSpecialization);
        System.out.println("Designation            : " + designation);
    }

    @Override
    public String toFileString() {
        return empCode + "," + empName + "," + empAddress + "," + empPhoneNumber + "," + basicPay + "," +
                calculateSalary() + ",Teaching," + subjectSpecialization + "," + designation;
    }
}

/**
 * Class representing Faculty Employees.
 */
class Faculty extends Teaching {
    private String researchArea;

    public Faculty(int empCode, String empName, String empAddress, int empPhoneNumber, double basicPay,
                   String subjectSpecialization, String designation, String researchArea) {
        super(empCode, empName, empAddress, empPhoneNumber, basicPay, subjectSpecialization, designation);
        this.researchArea = researchArea;
    }

    @Override
    public void displayAdditionalDetails() {
        super.displayAdditionalDetails();
        System.out.println("Research Area          : " + researchArea);
    }

    @Override
    public String toFileString() {
        return super.toFileString() + "," + researchArea;
    }
}

/**
 * Class representing Technical Employees.
 */
class Technical extends Teaching {
    private String technicalExpertArea;

    public Technical(int empCode, String empName, String empAddress, int empPhoneNumber, double basicPay,
                     String subjectSpecialization, String designation, String technicalExpertArea) {
        super(empCode, empName, empAddress, empPhoneNumber, basicPay, subjectSpecialization, designation);
        this.technicalExpertArea = technicalExpertArea;
    }

    @Override
    public void displayAdditionalDetails() {
        super.displayAdditionalDetails();
        System.out.println("Technical Expert Area : " + technicalExpertArea);
    }

    @Override
    public String toFileString() {
        return super.toFileString() + "," + technicalExpertArea;
    }
}

/**
 * Abstract class representing Office Employees.
 */
abstract class Office extends Employee {
    protected String position;

    public Office(int empCode, String empName, String empAddress, int empPhoneNumber, double basicPay,
                 String position) {
        super(empCode, empName, empAddress, empPhoneNumber, basicPay);
        this.position = position;
    }

    @Override
    public void displayAdditionalDetails() {
        System.out.println("Position               : " + position);
    }

    @Override
    public String toFileString() {
        return empCode + "," + empName + "," + empAddress + "," + empPhoneNumber + "," + basicPay + "," +
                calculateSalary() + ",Office," + position;
    }
}

/**
 * Class representing Administrative Employees.
 */
class Administrative extends Office {
    public Administrative(int empCode, String empName, String empAddress, int empPhoneNumber, double basicPay,
                           String position) {
        super(empCode, empName, empAddress, empPhoneNumber, basicPay, position);
    }
}

/**
 * Class representing Accounts Employees.
 */
class Accounts extends Office {
    public Accounts(int empCode, String empName, String empAddress, int empPhoneNumber, double basicPay,
                   String position) {
        super(empCode, empName, empAddress, empPhoneNumber, basicPay, position);
    }
}

/**
 * Main class for the Employee Management System.
 */
public class EmployeeManagementSystem {
    private static final String FILENAME = "employees.txt";
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("========================================");
        System.out.println("   Welcome to the Employee Management   ");
        System.out.println("========================================");

        while (true) {
            displayMenu();
            int choice = getUserChoice(1, 6);
            if (choice == 6) {
                System.out.println("Exiting... Goodbye!");
                break;
            }
            handleUserChoice(choice);
        }
        scanner.close();
    }

    /**
     * Displays the main menu.
     */
    private static void displayMenu() {
        System.out.println("\n========================================");
        System.out.println("          Main Menu");
        System.out.println("========================================");
        System.out.println("1. Add Faculty");
        System.out.println("2. Add Technical Staff");
        System.out.println("3. Add Administrative Staff");
        System.out.println("4. Add Accounts Staff");
        System.out.println("5. Search Employee");
        System.out.println("6. Exit");
        System.out.println("========================================");
        System.out.print("Enter your choice (1-6): ");
    }

    /**
     * Gets a valid user choice within a specified range.
     *
     * @param min Minimum valid choice.
     * @param max Maximum valid choice.
     * @return Validated user choice.
     */
    private static int getUserChoice(int min, int max) {
        int choice = -1;
        while (true) {
            String input = scanner.nextLine().trim();
            try {
                choice = Integer.parseInt(input);
                if (choice >= min && choice <= max) {
                    break;
                } else {
                    System.out.print("Invalid choice. Please enter a number between " + min + " and " + max + ": ");
                }
            } catch (NumberFormatException e) {
                System.out.print("Invalid input! Please enter a valid number: ");
            }
        }
        return choice;
    }

    /**
     * Handles user choice by invoking appropriate methods.
     *
     * @param choice User's menu choice.
     */
    private static void handleUserChoice(int choice) {
        switch (choice) {
            case 1:
                addFaculty();
                break;
            case 2:
                addTechnicalStaff();
                break;
            case 3:
                addAdministrativeStaff();
                break;
            case 4:
                addAccountsStaff();
                break;
            case 5:
                searchEmployee();
                break;
            default:
                System.out.println("Invalid choice. Please try again.");
        }
    }

    /**
     * Collects common employee details from user input.
     *
     * @return Employee object with common details.
     */
    private static Employee collectCommonEmployeeDetails(String employeeType) {
        System.out.println("\nEnter " + employeeType + " Details:");
        int empCode = getIntInput("Enter Employee Code: ");
        String empName = getStringInput("Enter Employee Name: ");
        String empAddress = getStringInput("Enter Employee Address: ");
        int empPhoneNumber = getIntInput("Enter Employee Phone Number: ");
        double basicPay = getDoubleInput("Enter Basic Pay: ");
        return new EmployeeBase(empCode, empName, empAddress, empPhoneNumber, basicPay);
    }

    /**
     * Adds a Faculty employee.
     */
    private static void addFaculty() {
        EmployeeBase base = (EmployeeBase) collectCommonEmployeeDetails("Faculty");
        String subjectSpecialization = getStringInput("Enter Subject Specialization: ");
        String designation = getStringInput("Enter Designation: ");
        String researchArea = getStringInput("Enter Research Area: ");
        Faculty faculty = new Faculty(base.empCode, base.empName, base.empAddress, base.empPhoneNumber,
                base.basicPay, subjectSpecialization, designation, researchArea);
        displayAndSaveEmployee(faculty);
    }

    /**
     * Adds a Technical Staff employee.
     */
    private static void addTechnicalStaff() {
        EmployeeBase base = (EmployeeBase) collectCommonEmployeeDetails("Technical Staff");
        String subjectSpecialization = getStringInput("Enter Subject Specialization: ");
        String designation = getStringInput("Enter Designation: ");
        String technicalExpertArea = getStringInput("Enter Technical Expert Area: ");
        Technical technical = new Technical(base.empCode, base.empName, base.empAddress, base.empPhoneNumber,
                base.basicPay, subjectSpecialization, designation, technicalExpertArea);
        displayAndSaveEmployee(technical);
    }

    /**
     * Adds an Administrative Staff employee.
     */
    private static void addAdministrativeStaff() {
        EmployeeBase base = (EmployeeBase) collectCommonEmployeeDetails("Administrative Staff");
        String position = getStringInput("Enter Position: ");
        Administrative admin = new Administrative(base.empCode, base.empName, base.empAddress, base.empPhoneNumber,
                base.basicPay, position);
        displayAndSaveEmployee(admin);
    }

    /**
     * Adds an Accounts Staff employee.
     */
    private static void addAccountsStaff() {
        EmployeeBase base = (EmployeeBase) collectCommonEmployeeDetails("Accounts Staff");
        String position = getStringInput("Enter Position: ");
        Accounts accounts = new Accounts(base.empCode, base.empName, base.empAddress, base.empPhoneNumber,
                base.basicPay, position);
        displayAndSaveEmployee(accounts);
    }

    /**
     * Displays employee details and saves them to the file.
     *
     * @param employee Employee object to display and save.
     */
    private static void displayAndSaveEmployee(Employee employee) {
        employee.displayCommonDetails();
        employee.displayAdditionalDetails();
        try {
            saveToFile(employee);
            System.out.println("\nEmployee details saved successfully!");
        } catch (IOException e) {
            System.out.println("Error saving employee details: " + e.getMessage());
        }
    }

    /**
     * Saves an employee's details to the storage file.
     *
     * @param emp Employee object to save.
     * @throws IOException If an I/O error occurs.
     */
    private static void saveToFile(Employee emp) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILENAME, true))) {
            writer.write(emp.toFileString());
            writer.newLine();
        }
    }

    /**
     * Searches for an employee by code and name.
     */
    private static void searchEmployee() {
        System.out.println("\n--- Search Employee ---");
        int empCode = getIntInput("Enter Employee Code to search: ");
        String empName = getStringInput("Enter Employee Name to search: ");

        try (BufferedReader reader = new BufferedReader(new FileReader(FILENAME))) {
            String line;
            boolean found = false;

            while ((line = reader.readLine()) != null) {
                String[] empData = line.split(",");
                if (empData.length < 7) {
                    continue; // Skip improperly formatted lines
                }

                try {
                    int parsedCode = Integer.parseInt(empData[0]);
                    String parsedName = empData[1];

                    if (parsedCode == empCode && parsedName.equalsIgnoreCase(empName)) {
                        displayEmployeeFromData(empData);
                        found = true;
                        break;
                    }
                } catch (NumberFormatException e) {
                    // Skip lines with invalid number formats
                    continue;
                }
            }

            if (!found) {
                System.out.println("Employee not found.");
            }
        } catch (FileNotFoundException e) {
            System.out.println("Employee data file not found.");
        } catch (IOException e) {
            System.out.println("Error reading employee data: " + e.getMessage());
        }
    }

    /**
     * Displays employee details from the parsed data array.
     *
     * @param empData Array of employee data.
     */
    private static void displayEmployeeFromData(String[] empData) {
        System.out.println("\nEmployee Found:");
        System.out.println("----------------------------------------");
        System.out.println("Employee Code       : " + empData[0]);
        System.out.println("Employee Name       : " + empData[1]);
        System.out.println("Employee Address    : " + empData[2]);
        System.out.println("Employee Phone No.  : " + empData[3]);
        System.out.printf("Basic Pay           : %.2f%n", Double.parseDouble(empData[4]));
        System.out.printf("Salary              : %.2f%n", Double.parseDouble(empData[5]));

        String employeeType = empData[6];
        switch (employeeType) {
            case "Teaching":
                if (empData.length >= 9) {
                    System.out.println("Subject Specialization : " + empData[7]);
                    System.out.println("Designation            : " + empData[8]);
                    if (empData.length == 10) {
                        System.out.println("Research Area          : " + empData[9]);
                    } else if (empData.length == 10) {
                        System.out.println("Technical Expert Area : " + empData[9]);
                    }
                }
                break;
            case "Office":
                if (empData.length >= 8) {
                    System.out.println("Position               : " + empData[7]);
                }
                break;
            default:
                System.out.println("Unknown Employee Type.");
        }
        System.out.println("----------------------------------------\n");
    }

    /**
     * Prompts the user for an integer input with validation.
     *
     * @param prompt Prompt message.
     * @return Validated integer input.
     */
    private static int getIntInput(String prompt) {
        int value;
        while (true) {
            System.out.print(prompt);
            String input = scanner.nextLine().trim();
            try {
                value = Integer.parseInt(input);
                if (value < 0) {
                    System.out.println("Please enter a positive number.");
                    continue;
                }
                break;
            } catch (NumberFormatException e) {
                System.out.println("Invalid input! Please enter a valid integer.");
            }
        }
        return value;
    }

    /**
     * Prompts the user for a double input with validation.
     *
     * @param prompt Prompt message.
     * @return Validated double input.
     */
    private static double getDoubleInput(String prompt) {
        double value;
        while (true) {
            System.out.print(prompt);
            String input = scanner.nextLine().trim();
            try {
                value = Double.parseDouble(input);
                if (value < 0) {
                    System.out.println("Please enter a positive number.");
                    continue;
                }
                break;
            } catch (NumberFormatException e) {
                System.out.println("Invalid input! Please enter a valid number.");
            }
        }
        return value;
    }

    /**
     * Prompts the user for a non-empty string input.
     *
     * @param prompt Prompt message.
     * @return Validated string input.
     */
    private static String getStringInput(String prompt) {
        String input;
        while (true) {
            System.out.print(prompt);
            input = scanner.nextLine().trim();
            if (input.isEmpty()) {
                System.out.println("Input cannot be empty! Please try again.");
            } else {
                break;
            }
        }
        return input;
    }

    /**
     * Internal class to hold common employee details before creating specific employee types.
     */
    private static class EmployeeBase extends Employee {
        public EmployeeBase(int empCode, String empName, String empAddress, int empPhoneNumber, double basicPay) {
            super(empCode, empName, empAddress, empPhoneNumber, basicPay);
        }

        @Override
        public String toFileString() {
            // This method won't be used as EmployeeBase is only for collecting common details
            return "";
        }

        @Override
        public void displayAdditionalDetails() {
            // This method won't be used as EmployeeBase is only for collecting common details
        }
    }
}