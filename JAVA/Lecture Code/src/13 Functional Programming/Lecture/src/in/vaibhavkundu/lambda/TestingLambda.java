package in.vaibhavkundu.lambda;

public class TestingLambda {
    public static void main(String[] args) {
        TestingLambda test = new TestingLambda();
        int sum = test.sum(6, 7);
        test.printString(("Hi, Welcome Everyone"));

        // toPrint -> System.out.println(toPrint);
        // (a, b) -> a + b;
        // (a, b) -> {
        //   int sum = a + b;
        //   System.out.println(sum);
        // }
    }

    public void printString(String toPrint) {
        System.out.println(toPrint);
    }

    public int sum(int a, int b) {
        int sum = a + b;
        return sum;
    }
}