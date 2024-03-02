package in.vaibhavkundu.Challenge82;

import java.util.Arrays;

public class ArrayOperations {
    private int[] numbers;

    public ArrayOperations(int[] numbers) {
        this.numbers = numbers;
    }

    public class Statistics {
        double mean() {
            double sum = 0;
            for (int number : numbers) {
                sum += number;
            }
            return sum / numbers.length;
        }

        double median() {
            int n = numbers.length;
            Arrays.sort(numbers);
            if (n % 2 == 0) {
                return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
            } else {
                return numbers[n / 2];
            }
        }
    }
}
