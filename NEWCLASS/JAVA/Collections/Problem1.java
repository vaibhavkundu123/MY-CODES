// Write a program that reads in a series of first names and stores them in a LinkedList. Do not store duplicate names. Allow the user to search for a first name.

import java.util.LinkedList;
import java.util.Scanner;

public class Problem1 {
    public static void main(String[] args) {
        LinkedList<String> names = new LinkedList<>();
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter names (type 'exit' to stop):");
        while (true) {
            String name = sc.next();
            if (name.equalsIgnoreCase("exit")) break;
            if (!names.contains(name)) names.add(name);
        }

        System.out.print("Enter name to search: ");
        String searchName = sc.next();
        System.out.println(names.contains(searchName) ? "Name found." : "Name not found.");
        
        sc.close();
    }
}
