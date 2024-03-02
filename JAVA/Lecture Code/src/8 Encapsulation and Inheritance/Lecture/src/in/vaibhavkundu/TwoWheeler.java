package in.vaibhavkundu;

import in.vaibhavkundu.inheritance.Vehicle;

public class TwoWheeler extends Vehicle {
    public TwoWheeler() {
        //numberOfTires = 2;
        setNumberOfTires(2);
        numberOfTires = 4;
    }

    public void balance() {
        System.out.println("I am balancing on two tires");
    }
}
