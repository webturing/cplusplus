package contest04;

import java.util.Scanner;

/**
 * Created by fjinh on 2017/7/3.
 */
public class C {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int[] b = new int[10];
        for (int i = 1; i < 10; i++) {
            int sum = 1;
            for (int j = 1; j <= i; j++)
                sum *= j;
            b[i] = sum;
        }
        int n = cin.nextInt();
        while (n-- > 0) {
            int a = cin.nextInt();
            for (int i = 9; i >= 1; i--) {
                if (a >= b[i]) {
                    a -= b[i];
                }
            }
            if (a > 0) {
                System.out.println("No");
            } else {
                System.out.println("Yes");
            }
        }
    }

}
