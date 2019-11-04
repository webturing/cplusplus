package lec03am;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by zj on 17-6-30.
 * <p>
 * 12
 * 2 4 6 17 20 40 43 45 60 64 85 98
 * 17
 * 35 75 40 61 56 21 85 61 50 83 52 22 44 68 51 80 38
 * 0
 */
public class P1141 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int size = cin.nextInt();
            if (size == 0) break;
            int a[] = new int[size];
            for (int i = 0; i < size; i++) {
                a[i] = cin.nextInt();
            }
            Arrays.sort(a);
            System.out.print(a[0]);
            int visited = a[0];
            for (int i = 1; i < size; i++) {
                if (visited == a[i])
                    continue;
                System.out.print(" " + a[i]);
                visited = a[i];
            }
            System.out.println();
        }
        cin.close();

    }
}
