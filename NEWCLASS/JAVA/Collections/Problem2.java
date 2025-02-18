//Write a program that uses a StringTokenizer to tokenize a line of text input by the user and places each token in a treeSet. Print the elements of the treeSet. [Note: This should cause the elements to be printed in ascending sorted order.]

import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Problem2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a line of text: ");
        String line = sc.nextLine();
        
        StringTokenizer st = new StringTokenizer(line);
        TreeSet<String> tokens = new TreeSet<>();
        
        while (st.hasMoreTokens()) tokens.add(st.nextToken());
        
        System.out.println("Tokens in sorted order: " + tokens);
        sc.close();
    }

}
