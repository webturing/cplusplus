package contest03;

import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by fan on 17-7-1.
 */
public class A {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i=0; i<n; i++) {
            int data = cin.nextInt();
            if (map.containsKey(data)) {
                map.put(data, map.get(data)+1);
            }else
                map.put(data, 1);
        }
        for (int i : map.keySet()) {
            System.out.println(i + " " + map.get(i));
        }
        cin.close();
    }
}

