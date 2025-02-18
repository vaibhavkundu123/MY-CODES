class ReverseEachWord {
    public static void main(String[] args) {
        StringBuilder result = new StringBuilder();
        for (int i = args.length - 1; i >= 0; i--) {
            result.append(args[i]).append(" ");
        }
        System.out.println("Reversed words:");
        System.out.println(result.toString().trim());
    }
}
