// Write a program for Minimum delete operations to make all elements of array same [ Input: arr[] = {4, 3, 4, 4, 2, 4} Output: 2 ]

import java.util.HashMap;
import java.util.Scanner;

public class Problem10 {
    public static int minDeletions(int[] arr) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        int maxFreq = 0;
        for (int num : arr) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
            maxFreq = Math.max(maxFreq, freq.get(num));
        }
        return arr.length - maxFreq;
    }

    public static void main(String[] args) {
        int arr[];
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        arr = new int[sc.nextInt()];
        System.out.println("Enter elements of array A: ");
        for (int i = 0; i < arr.length; i++) arr[i] = sc.nextInt();
        sc.close();
        System.out.println(minDeletions(arr));
    }
}
