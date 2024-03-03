package in.vaibhavkundu.enums;

public class TestingEnums {
    public static void main(String[] args) {
        TrafficLight color = TrafficLight.RED;
        //color = "RED";
        color = TrafficLight.GREEN;

        Grade grade = Grade.valueOf("D");
        for (Grade value : Grade.values()) {
            System.out.println(value);
        }
    }
}
