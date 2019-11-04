package contest03;


import java.io.IOException;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * Created by WebTuring on 2017-7-3.
 */
public class P1797 {
    public static void main(String[] args) throws IOException {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        TreeMap<Integer, Integer> freq = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            int cur = cin.nextInt();
            if (freq.containsKey(cur)) {
                freq.put(cur, freq.get(cur)+1);
            } else {
                freq.put(cur, 1);
            }
        }
        for (Integer key : freq.keySet())
            System.out.println(key + " " + freq.get(key));
    }
}
