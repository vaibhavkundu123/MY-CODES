// Write a program an array, arr[0..n-1] of distinct elements and a range [low, high], find all numbers that are in a range, but not the array.  [ Input: arr[] = {10, 12, 11, 15}, low = 10, high = 15   Output: 13, 14 ]

import java.util.HashSet;
import java.util.Scanner;

public class Problem9 {
    public static void findMissing(int[] arr, int low, int high) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : arr) set.add(num);

        for (int i = low; i <= high; i++) 
            if (!set.contains(i)) System.out.print(i + " ");
    }

    public static void main(String[] args) {
        int arr[], low, high;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        arr = new int[sc.nextInt()];
        System.out.println("Enter elements of array A: ");
        for (int i = 0; i < arr.length; i++) arr[i] = sc.nextInt();
        System.out.println("Enter the lower limit: ");
        low = sc.nextInt();
        System.out.println("Enter the upper limit: ");
        high = sc.nextInt();
        sc.close();
        findMissing(arr, low, high);
    }
}
