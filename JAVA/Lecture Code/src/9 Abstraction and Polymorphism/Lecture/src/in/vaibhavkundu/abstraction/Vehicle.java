package in.vaibhavkundu.abstraction;

public abstract class Vehicle implements Transport {
    private int noOfTiers;

    public abstract void makeStartSound();

//    @Override
//    public void getSetGo() {
//        System.out.println("Going to place.......");
//    }

    public Vehicle(int noOfTiers) {
        this.noOfTiers = noOfTiers;
    }

    public int getNoOfTiers() {
        return noOfTiers;
    }

    public void setNoOfTiers(int noOfTiers) {
        this.noOfTiers = noOfTiers;
    }

    public void commute() {
        System.out.println("Going.....");
    }
}
