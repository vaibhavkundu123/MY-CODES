// Write a program to find the most frequent element in the given array. If there are multiple elements that appear a maximum number of times, print any one of them.

import java.util.HashMap;
import java.util.Scanner;

public class Problem11 {
    public static void main(String[] args) {
        int arr[];
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        arr = new int[sc.nextInt()];
        System.out.println("Enter elements of array A: ");
        for (int i = 0; i < arr.length; i++) arr[i] = sc.nextInt();
        sc.close();
        
        HashMap<Integer, Integer> freq = new HashMap<>();
        int maxFreq = 0, mostFrequent = arr[0];

        for (int num : arr) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
            if (freq.get(num) > maxFreq) {
                maxFreq = freq.get(num);
                mostFrequent = num;
            }
        }

        System.out.println("Most Frequent: " + mostFrequent);
    }
}
