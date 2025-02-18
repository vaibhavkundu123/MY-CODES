// Write a program to check the number where the difference between every adjacent digit should be 1 using ArrayList.

import java.util.Scanner;

public class Problem6 {
    public static boolean checkNumber(int num) {
        int prevDigit = num % 10;
        num /= 10;
        while (num > 0) {
            int currentDigit = num % 10;
            if (Math.abs(currentDigit - prevDigit) != 1) return false;
            prevDigit = currentDigit;
            num /= 10;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number: ");
        int num = sc.nextInt();
        System.out.println(checkNumber(num) ? "Valid" : "Invalid");
        sc.close();
    }
}
