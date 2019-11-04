package lec03am;

import java.util.Scanner;
import java.util.TreeSet;

/**
 * Created by zj on 17-6-30.
 * <p>
 * 12
 * 2 4 6 17 20 40 43 45 60 64 85 98
 * 17
 * 35 75 40 61 56 21 85 61 50 83 52 22 44 68 51 80 38
 * 0
 */
public class P1141b {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int size = cin.nextInt();
            if (size == 0) break;
            TreeSet<Integer> set = new TreeSet<Integer>();
            for (int i = 0; i < size; i++)
                set.add(cin.nextInt());
            System.out.println(set);
            for (Integer i : set)
                System.out.println(i);
        }
        cin.close();

    }
}
