package week2contest;

/**
 * Created by fan on 2017/7/11.
 */

import java.util.Scanner;


public class A {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        for (int cnt = 1; cnt <= t; cnt++) {
            System.out.print("Case #" + cnt + ": ");
            int n = cin.nextInt();
            double s = cin.nextDouble();
            double sum = 0;
            for (int i = 0; i < n; i++) {
                sum += cin.nextDouble() * cin.nextDouble();
            }
            long ss = (long) (sum * 100);
            double ans = 0;
            if (ss % 10 != 0) {
                sum = sum + 0.1 - (ss % 10) * 0.01;
            }
            ans = s - sum;
            if (ans < 0) {
                System.out.println(-1);
            } else
                System.out.printf("%.2f\n", ans);

        }
        cin.close();
    }
}