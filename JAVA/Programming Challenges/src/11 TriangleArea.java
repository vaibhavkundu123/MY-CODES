import java.util.Scanner;

class TriangleArea {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Welcome to area calculator\n");
        System.out.print("Please enter your base in cms: ");
        double base = input.nextDouble();
        System.out.print("Please enter your height in cms: ");
        double height = input.nextDouble();

        double area = (base * height) / 2;

        System.out.println("The area of your triangle is: " + area + "cms2");
    }
}
