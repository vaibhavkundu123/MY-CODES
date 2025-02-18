class ArrayExample {
    public static void main(String[] args) {
        String[] Products = {
            "Laptop",
            "Smartphone",
            "Tablet",
            "Headphones",
            "Keyboard",
            "Mouse",
            "Monitor",
            "Printer",
            "Camera",
            "Smartwatch"
        };

        System.out.println("List of Products:");
        for (int i = 0; i < Products.length; i++) {
            System.out.println("Product " + (i + 1) + ": " + Products[i]);
        }
    }
}
