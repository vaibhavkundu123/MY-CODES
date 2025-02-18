// Write a program to find the only repetitive element  in a given array. [Input  : a[] = {1, 3, 2, 3, 4}  Output : 3 ]

import java.util.HashSet;
import java.util.Scanner;

public class Problem8 {
    public static int findDuplicate(int[] arr) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : arr) {
            if (!set.add(num)) return num;
        }
        return -1;
    }

    public static void main(String[] args) {
        int arr[];
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        arr = new int[sc.nextInt()];
        System.out.println("Enter elements of array A: ");
        for (int i = 0; i < arr.length; i++) arr[i] = sc.nextInt();
        sc.close();
        System.out.println("Duplicate: " + findDuplicate(arr));
    }
}
