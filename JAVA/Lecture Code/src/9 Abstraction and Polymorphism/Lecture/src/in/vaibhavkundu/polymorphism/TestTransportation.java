package in.vaibhavkundu.polymorphism;

public class TestTransportation {
    public static void main(String[] args) {
        Car car = new Car();
        //Vehicle vehicle = new Vehicle();
        Plane plane = new Plane();

//        car.start();
//        plane.start();

        //castTest(vehicle);
        castTest(car);
        castTest(plane);

        //Vehicle vCar = new Car();
        //Car cVehicle = new Vehicle();
        //Car cVehicle = (Car) new Vehicle();

        //Object ref1 = new Car();
        //Object ref2 = new Vehicle();
    }

    private static void castTest(Vehicle vehicle) {
        //Car cVehicle = (Car) vehicle;
        //vehicle.noOfDoors();
        //cVehicle.start();
        //cVehicle.noOfDoors();
        vehicle.start();

        if (vehicle instanceof Car) {

        }
    }
}
