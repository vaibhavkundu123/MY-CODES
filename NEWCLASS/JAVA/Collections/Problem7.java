//Write a program where an array A[] and a number x are given, check for pairs in A[] with sum as x.

import java.util.HashSet;
import java.util.Scanner;

class Problem7 {
    public static void findPairs(int[] arr, int x) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : arr) {
            int diff = x - num;
            if (set.contains(diff)) System.out.println(num + ", " + diff);
            set.add(num);
        }
    }
    public static void main(String[] args)
    {
        int arr[], x;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        arr = new int[sc.nextInt()];
        System.out.println("Enter elements of array A: ");
        for (int i = 0; i < arr.length; i++) arr[i] = sc.nextInt();
        System.out.println("Enter the sum: ");
        x = sc.nextInt();
        sc.close();
        findPairs(arr, x);
    }
}