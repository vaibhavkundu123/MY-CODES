package in.vaibhavkundu.Challenge79;

public class TestEmployee {
    public static void main(String[] args) {
        Employee employee = new Employee("Vaibhav", 19, 25000);
        System.out.println(employee.getEmployeeDetails());
        employee.setName("Om");
        System.out.println(employee.getEmployeeDetails());
    }
}
