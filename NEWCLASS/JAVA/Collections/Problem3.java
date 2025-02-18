// Write a program that inputs the names of people into different array list, A and B.
// Array A has N number of names while array B has M number of names, with no duplicates in either of them. Merge arrays A and B into a single array list C, such that the resulting array list is sorted alphabetically.
// Display all the three arrays list, A, B and C, stored alphabetically.

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Problem3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> A = new ArrayList<>();
        ArrayList<String> B = new ArrayList<>();

        System.out.print("Enter number of names in A: ");
        int n = sc.nextInt();
        System.out.println("Enter names for A:");
        for (int i = 0; i < n; i++) A.add(sc.next());

        System.out.print("Enter number of names in B: ");
        int m = sc.nextInt();
        System.out.println("Enter names for B:");
        for (int i = 0; i < m; i++) B.add(sc.next());

        ArrayList<String> C = new ArrayList<>(A);
        C.addAll(B);
        Collections.sort(C);

        System.out.println("Sorted A: " + A);
        System.out.println("Sorted B: " + B);
        System.out.println("Merged Sorted C: " + C);

        sc.close();
    }
}
