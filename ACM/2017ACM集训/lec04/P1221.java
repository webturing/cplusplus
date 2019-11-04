package lec04am;

import java.util.Arrays;
import java.util.TreeMap;

/**
 * Created by zj on 17-7-1.
 */
public class P1221 {
    public static void main(String[] args) {
        String[] words = "to know everything is to know nothing".split(" ");
        System.out.println(Arrays.toString(words));
        TreeMap<String, Integer> freq = new TreeMap<>();
        for (String word : words) {
            if (freq.containsKey(word)) {
                int old = freq.get(word);
                freq.put(word, old + 1);
            } else {
                freq.put(word, 1);
            }
        }
        System.out.println(freq);
        System.out.println(words.length);
        for (String key : freq.keySet()) {
            System.out.println(String.format("%s:%d", key, freq.get(key)));
        }
    }
}
