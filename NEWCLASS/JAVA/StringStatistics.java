import java.util.Scanner;

public class StringStatistics {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string:");
        String input = scanner.nextLine();

        int upperCaseCount = 0;
        int lowerCaseCount = 0;
        int digitCount = 0;
        int spaceCount = 0;

        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            if (Character.isUpperCase(ch)) {
                upperCaseCount++;
            } else if (Character.isLowerCase(ch)) {
                lowerCaseCount++;
            } else if (Character.isDigit(ch)) {
                digitCount++;
            } else if (Character.isWhitespace(ch)) {
                spaceCount++;
            }
        }

        System.out.println("Statistics:");
        System.out.println("Count of uppercase characters: " + upperCaseCount);
        System.out.println("Count of lowercase characters: " + lowerCaseCount);
        System.out.println("Count of digits: " + digitCount);
        System.out.println("Count of spaces: " + spaceCount);

        scanner.close();
    }
}
