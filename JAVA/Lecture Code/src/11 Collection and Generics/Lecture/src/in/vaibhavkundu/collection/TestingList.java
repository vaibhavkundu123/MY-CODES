package in.vaibhavkundu.collection;

import java.util.ArrayList;
import java.util.List;

public class TestingList {
    public static void main(String[] args) {
        List<String> strList = new ArrayList();
        strList.add("Vaibhav");
        strList.add("Kundu");
        //strList.add(54);

        for (int i = 0; i < strList.size(); i++) {
            System.out.print(strList.get(i));
        }
        System.out.println();
        System.out.println(strList.size());

        strList.add(1, "Om");
        for (int i = 0; i < strList.size(); i++) {
            System.out.print(strList.get(i));
        }
        System.out.println();
        System.out.println(strList.size());

        strList.remove(0);

        if (strList.contains("Kundu")) {
            System.out.println("Kundu exists");
        }

        if (strList.contains("Kundu")) {
            System.out.println(strList.indexOf("Kundu"));
        }

        for (int i = 0; i < strList.size(); i++) {
            System.out.print(strList.get(i));
        }
    }
}
