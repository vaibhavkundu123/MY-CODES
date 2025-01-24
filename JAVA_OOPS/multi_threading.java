import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class FibonacciThread extends Thread {

    private int terms;

    public FibonacciThread(int terms) {
        this.terms = terms;
    }

    @Override
    public void run() {
        int a = 0, b = 1;
        System.out.println("Fibonacci Series:");
        for (int i = 1; i <= terms; i++) {
            System.out.print(a + " ");
            int next = a + b;
            a = b;
            b = next;
            try {
                Thread.sleep(1000); // 1000 ms = 1 second
            } catch (InterruptedException e) {
                System.out.println("Fibonacci thread interrupted");
            }
        }
        System.out.println("\nFibonacci thread finished.");
    }
}

class PrimeThread extends Thread {

    private int start, end;

    public PrimeThread(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public void run() {
        System.out.println("Prime Numbers:");
        for (int num = start; num <= end; num++) {
            if (isPrime(num)) {
                System.out.print(num + " ");
                try {
                    Thread.sleep(500); // 500 ms = 0.5 second
                } catch (InterruptedException e) {
                    System.out.println("Prime thread interrupted");
                }
            }
        }
        System.out.println("\nPrime thread finished.");
    }

    private boolean isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

public class multi_threading {

    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        try {
            // Taking user input
            System.out.print("Enter the number of terms for Fibonacci series: ");
            int fibonacciTerms = Integer.parseInt(reader.readLine());

            System.out.print("Enter the starting range for prime numbers: ");
            int primeStart = Integer.parseInt(reader.readLine());

            System.out.print("Enter the ending range for prime numbers: ");
            int primeEnd = Integer.parseInt(reader.readLine());

            // Creating threads
            FibonacciThread fibonacciThread = new FibonacciThread(fibonacciTerms);
            PrimeThread primeThread = new PrimeThread(primeStart, primeEnd);

            // Starting threads
            fibonacciThread.start();
            primeThread.start();
        } catch (IOException e) {
            System.out.println("An error occurred while reading input.");
        } catch (NumberFormatException e) {
            System.out.println("Please enter valid integer values.");
        }
    }
}
