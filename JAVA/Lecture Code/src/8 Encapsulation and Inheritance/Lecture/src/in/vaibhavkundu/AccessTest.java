package in.vaibhavkundu;

public class AccessTest {
    public static void main(String[] args) {
        Car car = new Car();
        car.color = "Red";
        car.model = "Swift";
        System.out.println(car);
        car.costOfPurchase = 7896;
        //car.fuelLevel = 5;
        Car newCar = new Car("Black", "BMW", 1, 5000);
        System.out.println(newCar);

        Default def = new Default();
    }
}
