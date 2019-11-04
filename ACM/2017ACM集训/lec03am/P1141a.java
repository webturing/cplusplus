package lec03am;

import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

/**
 * Created by zj on 17-6-30.
 * <p>
 * 12
 * 2 4 6 17 20 40 43 45 60 64 85 98
 * 17
 * 35 75 40 61 56 21 85 61 50 83 52 22 44 68 51 80 38
 * 0
 */
public class P1141a {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int size = cin.nextInt();
            if (size == 0) break;
            Vector<Integer> v = new Vector<Integer>();
            for (int i = 0; i < size; i++) {
                int k = cin.nextInt();
                if (v.contains(k))
                    continue;
                v.add(k);
            }
            /**
             Collections.sort(v,Collections.<Integer>reverseOrder());
             Collections.sort(v, new Comparator<Integer>() {
            @Override public int compare(Integer ia, Integer ib) {
            return ib-ia;
            }
            })
             */
            Collections.sort(v);
            System.out.println(v);
        }
        cin.close();

    }
}
