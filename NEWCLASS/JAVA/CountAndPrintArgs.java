public class CountAndPrintArgs {
    public static void main(String[] args) {
        int numArgs = args.length;
        System.out.print("No. of arguments - " + numArgs + " ");
        StringBuilder firstLetters = new StringBuilder();
        for (int i = 0; i < numArgs; i++) {
            firstLetters.append(args[i].charAt(0));
        }
        System.out.println(firstLetters.toString());
    }
}