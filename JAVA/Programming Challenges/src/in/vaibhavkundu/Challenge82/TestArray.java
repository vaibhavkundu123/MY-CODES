package in.vaibhavkundu.Challenge82;

public class TestArray {
    public static void main(String[] args) {
        ArrayOperations opr = new ArrayOperations(new int[]{1,3,5,9,13});
        ArrayOperations.Statistics statistics = opr.new Statistics();
        System.out.println(statistics.mean());
        System.out.println(statistics.median());
    }
}
