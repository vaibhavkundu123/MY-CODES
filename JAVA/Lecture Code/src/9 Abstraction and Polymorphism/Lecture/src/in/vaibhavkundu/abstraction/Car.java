package in.vaibhavkundu.abstraction;

public class Car extends Vehicle{
    private int noOfDoors;

    public Car() {
        super(4);
    }

    @Override
    public void makeStartSound() {
        System.out.println("Vroommm.......");
    }

    @Override
    public void getSetGo() {
        System.out.println("Going to place.......");
    }
}
