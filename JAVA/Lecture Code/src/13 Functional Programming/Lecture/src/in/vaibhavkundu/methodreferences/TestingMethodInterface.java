package in.vaibhavkundu.methodreferences;

import java.util.List;
import java.util.function.BinaryOperator;

public class TestingMethodInterface {
    public static void main(String[] args) {
        List<Integer> numbers = List.of(1,3,4,2,5,6,3);

        numbers.stream()
                .filter(num -> num % 2 == 1)
                .forEach(num -> System.out.println(num));

        System.out.println();

        numbers.stream()
                .filter(num -> num % 2 == 1)
                .forEach(System.out::println);

        int newSum1 = numbers.stream()
                .reduce(0, (a, b) -> a + b);
        System.out.printf("\nSum using reduce and lambda is %d", newSum1);

        System.out.println();

        int newSum2 = numbers.stream()
                .reduce(0, Integer::sum);
        System.out.printf("\nSum using reduce and lambda is %d", newSum2);


    }
}
