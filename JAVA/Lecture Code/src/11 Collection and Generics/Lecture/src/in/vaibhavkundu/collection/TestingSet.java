package in.vaibhavkundu.collection;

import java.util.HashSet;
import java.util.Set;

public class TestingSet {
    public static void main(String[] args) {
        Set<String> names = new HashSet();
        System.out.println(names.add("Vaibhav"));
        System.out.println(names.add("Kundu"));
        System.out.println(names.add("Om"));
        Utility.print(names);

        System.out.println(names.add("Vaibhav"));
        System.out.println(names.size());
        Utility.print(names);

        System.out.println(names.contains("Vaibhav"));
        System.out.println(names.remove("Vaibhav"));
        Utility.print(names);
        System.out.println(names.remove("Vaibhav"));
    }
}
