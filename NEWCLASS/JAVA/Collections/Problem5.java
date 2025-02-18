// Write a program to find elements which are present in first array and not in second array.

import java.util.HashSet;
import java.util.Scanner;

public class Problem5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] A;
        int[] B;
        System.out.println("Enter size of array A: ");
        A = new int[sc.nextInt()];
        System.out.println("Enter elements of array A: ");
        for (int i = 0; i < A.length; i++) A[i] = sc.nextInt();
        System.out.println("Enter size of array B: ");
        B = new int[sc.nextInt()];
        System.out.println("Enter elements of array B: ");
        for (int i = 0; i < B.length; i++) B[i] = sc.nextInt();
        sc.close();

        HashSet<Integer> setB = new HashSet<>();
        for (int num : B) setB.add(num);
        for (int num : A) if (!setB.contains(num)) System.out.print(num + " ");
    }
}
