interface A {
    // void show();
    // void display();
    double getValue();
}

// class B implements A {
//     public void show() {
//         System.out.println("Hello");
//     }
// }

class New {
    public static void main(String[] args) {
        // A obj = new A() {
        //     public void show() {
        //         System.out.println("Hi");
        //     }
        //     public void display() {
        //         System.out.println("Hello");
        //     }
        // };
        // obj.show();
        // obj.display();
        A myNum;
        myNum = () -> 123.45;
        System.out.println(myNum.getValue());
    }
}