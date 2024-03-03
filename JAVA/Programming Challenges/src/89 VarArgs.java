class VarArgs {

    public static void main(String[] args) {
        System.out.println(concatenate("Vaibhav"));

        System.out.println(concatenate("Vaibhav", "Kundu"));

        System.out.println(concatenate("Welcome", "everyone", "to", "my", "code"));
    }

    public static String concatenate(String... strs) {
        StringBuilder sb = new StringBuilder();
        for (String str : strs) {
            sb.append(str).append(" ");
        }
        return sb.toString();
    }

//    public static StringBuilder concatenate(String... strs) {
//        StringBuilder sb = new StringBuilder();
//        for (String str : strs) {
//            sb.append(str).append(" ");
//        }
//        return sb;
//    }
}
