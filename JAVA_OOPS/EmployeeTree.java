import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Employee
{
    int emp_code;
    String emp_name;
    String emp_address;
    int emp_pn_no;
    final double da = 0.1;
    final double hra = 0.2;
    double basic_pay;
    Employee(int ec, String en, String ea, int epn, double bp)
    {
        emp_code = ec;
        emp_name = en;
        emp_address = ea;
        emp_pn_no = epn;
        basic_pay = bp;
    }
    void salary()
    {
        System.out.println("Salary : " + (basic_pay + basic_pay * da + basic_pay * hra)); 
    }
    void display()
    {
        System.out.println("Employee Code : " + emp_code);
        System.out.println("Employee Name : " + emp_name);
        System.out.println("Employee Address : " + emp_address);
        System.out.println("Employee Phone Number : " + emp_pn_no);
    }
}

class Teaching extends Employee
{
    String subject_specialization;
    String designation;
    Teaching(int ec, String en, String ea, int epn, double bp, String ss, String d)
    {
        super(ec, en, ea, epn, bp);
        subject_specialization = ss;
        designation = d;
    }
    void display()
    {
        super.display();
        System.out.println("Subject Specialization : " + subject_specialization);
        System.out.println("Designation : " + designation);
    }
}

class Office extends Employee
{
    String position;
    Office(int ec, String en, String ea, int epn, double bp, String p)
    {
        super(ec, en, ea, epn, bp);
        position = p;
    }
    void display()
    {
        super.display();
        System.out.println("Position : " + position);
    }
}

class Faculty extends Teaching
{
    String research_area;
    Faculty(int ec, String en, String ea, int epn, double bp, String ss, String d, String ra)
    {
        super(ec, en, ea, epn, bp, ss, d);
        research_area = ra;
    }
    void display()
    {
        super.display();
        System.out.println("Research Area : " + research_area);
    }
}

class Technical extends Teaching
{
    String tech_expert_area;
    Technical(int ec, String en, String ea, int epn, double bp, String ss, String d, String tea)
    {
        super(ec, en, ea, epn, bp, ss, d);
        tech_expert_area = tea;
    }
    void display()
    {
        super.display();
        System.out.println("Technical Expert Area : " + tech_expert_area);
    }
}

class Administrative extends Office
{
    Administrative(int ec, String en, String ea, int epn, double bp, String p)
    {
        super(ec, en, ea, epn, bp, p);
    }
    void display()
    {
        super.display();
    }
}

class Accounts extends Office
{
    Accounts(int ec, String en, String ea, int epn, double bp, String p)
    {
        super(ec, en, ea, epn, bp, p);
    }
    void display()
    {
        super.display();
    }
}

class EmployeeTree
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            System.out.println();
            System.out.println("1. Faculty");
            System.out.println("2. Technical");
            System.out.println("3. Administrative");
            System.out.println("4. Accounts");
            System.out.println("5. Exit");
            System.out.println();

            int choice = Integer.parseInt(br.readLine());

            if (choice == 5) {
                System.out.println();
                break;
            }
            System.out.println();
            System.out.println("Enter employee code:");
            int ec = Integer.parseInt(br.readLine());
            System.out.println("Enter employee name:");
            String en = br.readLine();
            System.out.println("Enter employee address:");
            String ea = br.readLine();
            System.out.println("Enter employee phone number:");
            int epn = Integer.parseInt(br.readLine());
            System.out.println("Enter basic pay:");
            double bp = Double.parseDouble(br.readLine());

            switch (choice) {
            case 1:
                System.out.println("Enter subject specialization:");
                String ss3 = br.readLine();
                System.out.println("Enter designation:");
                String d3 = br.readLine();
                System.out.println("Enter research area:");
                String ra3 = br.readLine();
                Faculty faculty = new Faculty(ec, en, ea, epn, bp, ss3, d3, ra3);
                System.out.println();
                faculty.display();
                faculty.salary();
                break;

            case 2:
                System.out.println("Enter subject specialization:");
                String ss4 = br.readLine();
                System.out.println("Enter designation:");
                String d4 = br.readLine();
                System.out.println("Enter technical expert area:");
                String tea4 = br.readLine();
                Technical technical = new Technical(ec, en, ea, epn, bp, ss4, d4, tea4);
                System.out.println();
                technical.display();
                technical.salary();
                break;

            case 3:
                System.out.println("Enter position:");
                String p5 = br.readLine();
                Administrative administrative = new Administrative(ec, en, ea, epn, bp, p5);
                System.out.println();
                administrative.display();
                administrative.salary();
                break;

            case 4:
                System.out.println("Enter position:");
                String p6 = br.readLine();
                Accounts accounts = new Accounts(ec, en, ea, epn, bp, p6);
                System.out.println();
                accounts.display();
                accounts.salary();
                break;

            default:
                System.out.println("Invalid choice");
                break;
            }
        }
    }
}
