package in.vaibhavkundu.map;

import java.util.HashMap;
import java.util.Map;

public class TestingMap {
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        map.put("Vaibhav", 34);
        map.put("Om", 100);
        map.put("Ram", 100);
        map.put("sohan", 0);
        System.out.println(map.size());
        System.out.println(map.get("Vaibhav"));
        System.out.println(map.containsKey("Ram"));
        System.out.println(map.containsKey("Geeta"));
        System.out.println(map.remove("sohan"));
        System.out.println(map.size());

        for (String key : map.keySet()) {
            System.out.printf("%s : %s\n", key, map.get(key));
        }
    }
}
