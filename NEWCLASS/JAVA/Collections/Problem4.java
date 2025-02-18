// Write a program to find whether an array is subset of another array or not.

import java.util.HashSet;
import java.util.Scanner;

public class Problem4 {
    public static boolean isSubset(int[] A, int[] B) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : A) set.add(num);
        for (int num : B) if (!set.contains(num)) return false;
        return true;
    }

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
        System.out.println(isSubset(A, B) ? "B is a subset of A" : "B is not a subset of A");
    }
}
