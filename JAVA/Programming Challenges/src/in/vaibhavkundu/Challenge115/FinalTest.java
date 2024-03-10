package in.vaibhavkundu.Challenge115;

import java.util.List;
import java.util.Map;

public class FinalTest {
    public static void main(String[] args) {
        List<String> numbers = List.of("1", "2", "3", "4", "5");

        numbers.stream()
                .map(Integer::parseInt)
                .map(num -> Math.pow(num, 2))
                .reduce(Double::sum)
                .ifPresent(System.out::println);
    }
}
