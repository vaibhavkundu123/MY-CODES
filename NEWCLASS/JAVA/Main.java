class VowelCounter {
    int vCnt = 0;
    void CountVowels(char ch) {
        char lowerChar = Character.toLowerCase(ch);
        if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || lowerChar == 'o' || lowerChar == 'u') {
            vCnt++;
        }
    }
    public int getVowelCount() {
        return vCnt;
    }
}

public class Main {
    public static void main(String[] args) {
        VowelCounter counter = new VowelCounter();

        char[] testChars = {'A', 'b', 'E', 'i', 'O', 'u', 'x', 'z'};
        for (char ch : testChars) {
            counter.CountVowels(ch);
        }

        System.out.println("Total number of vowels: " + counter.getVowelCount());
    }
}
