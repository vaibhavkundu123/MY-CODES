class UniqueCharacters {
    static boolean hasAllUniqueCharacters(String str) {
        str = str.replace(" ", "");

        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j < str.length(); j++) {
                if (str.charAt(i) == str.charAt(j)) {
                    return false;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
        String input1 = "ab cd 10jk";
        String input2 = "hutg9mnd!nk9";

        System.out.println("Input: " + input1);
        System.out.println("Output: " + hasAllUniqueCharacters(input1));

        System.out.println("Input: " + input2);
        System.out.println("Output: " + hasAllUniqueCharacters(input2));
    }
}
