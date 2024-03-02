package in.vaibhavkundu.abstraction;

public class TestAbstraction {
    public static void main(String[] args) {
        //Vehicle vehicle = new Vehicle(2);
        Car car = new Car();
        car.commute();
        car.makeStartSound();
    }
}
