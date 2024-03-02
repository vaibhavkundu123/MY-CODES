package in.vaibhavkundu.polymorphism;

class Car extends Vehicle{

    public Car() {
        super();
    }

    Car(int noOfTiers) {
        super(noOfTiers);
    }

    public int noOfDoors() {
        return 5;
    }

//    @Override
//    public void start() {
//        System.out.println(super.getNoOfTiers());
//        System.out.println("Car is starting.......");
//    }
}
