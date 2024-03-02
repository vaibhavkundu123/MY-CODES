class StringManipulation {
    public static void main(String[] args) {
        String firstName = "Vaibhav";
        String lasName = "Kundu";
        //String fullName = firstName + " " + lasName;
        String fullName = firstName.concat(" ").concat(lasName);
        System.out.println(fullName);
        System.out.println(fullName.toUpperCase());
    }
}
