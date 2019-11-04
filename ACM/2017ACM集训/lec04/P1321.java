package lec04;

import java.io.PrintWriter;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Map应用：
 * 键 为浮点数 （元组）
 */
public class P1321 {
    static Scanner cin = new Scanner(System.in);
    static PrintWriter cout = new PrintWriter(System.out);

    public static void main(String[] args) {
        while (cin.hasNext()) {
            int m = cin.nextInt();
            Map<Double, Integer> mp = new HashMap<Double, Integer>();
            for (int i = 0; i < m; i++) {
                Double slop = cin.nextDouble() / cin.nextDouble();
                if (mp.containsKey(slop))
                    mp.put(slop, mp.get(slop) + 1);
                else
                    mp.put(slop, 1);
            }
            cout.println(Collections.max(mp.values()));

        }
        cout.close();
        cin.close();
    }

}
