package in.vaibhav;

import in.gettersetter.Car;

public class getterTest {
    public static void main(String[] args) {
        Car car = new Car("Red", "Maruti", 3, 8000);
        //car.setColor("Blue");
        System.out.printf("%s\n%s", car.getColor(), car.getModel());
    }

}
