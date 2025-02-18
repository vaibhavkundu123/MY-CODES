// Write a program an array arr[] of length N, find the length of the longest subarray with a sum equal to 0.

import java.util.HashMap;
import java.util.Scanner;

public class Problem12 {
    public static int findMaxLength(int[] arr) {
        HashMap<Integer, Integer> sumIndexMap = new HashMap<>();
        int maxLength = 0, sum = 0;

        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (sum == 0) maxLength = i + 1;
            if (sumIndexMap.containsKey(sum)) maxLength = Math.max(maxLength, i - sumIndexMap.get(sum));
            else sumIndexMap.put(sum, i);
        }
        return maxLength;
    }

    public static void main(String[] args) {
        int arr[];
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        arr = new int[sc.nextInt()];
        System.out.println("Enter elements of array A: ");
        for (int i = 0; i < arr.length; i++) arr[i] = sc.nextInt();
        sc.close();  
        System.out.println("Length of longest subarray with sum 0: " + findMaxLength(arr));
    }
}
