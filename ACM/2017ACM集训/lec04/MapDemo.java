package lec04am;

import java.util.Map;
import java.util.TreeMap;

/**
 * Created by zj on 17-7-1.
 */
public class MapDemo {
    public static void main(String[] args) {
        Map<String,String> contacts=new TreeMap<>();
        System.out.println(contacts);
        contacts.put("tom","123456");
        System.out.println(contacts.containsKey("cat"));
        contacts.put("cat","9876543");
        System.out.println(contacts);
        System.out.println(contacts.get("tom"));
        //contacts.clear();
        contacts.remove("tom");
        System.out.println(contacts.get("tom"));
    }
}
