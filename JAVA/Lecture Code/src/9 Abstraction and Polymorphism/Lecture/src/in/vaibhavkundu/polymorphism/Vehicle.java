package in.vaibhavkundu.polymorphism;

public abstract class Vehicle {

    private int noOfTiers;

    public Vehicle() {
        this.noOfTiers = 0;
    }

    public Vehicle(int noOfTiers) {
        this.noOfTiers = noOfTiers;
    }

    public int getNoOfTiers() {
        return noOfTiers;
    }

    public final void start() {
        System.out.println("Vehicle is starting.......");
    }
}
