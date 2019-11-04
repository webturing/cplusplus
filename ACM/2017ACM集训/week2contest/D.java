package week2contest;


import java.util.Scanner;

/**
 * Created by fan on 2017/7/10.
 */
public class D {
    static int wi[], vi[];
    static int INF = 1<<30;
    static int dp[] = new int[10005];
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt(), w = cin.nextInt();
            int sumv = 0;
            wi = new int[n];
            vi = new int[n];
            for (int i = 0; i < n; i++) {
                wi[i] = cin.nextInt();
                vi[i] = cin.nextInt();
                sumv += vi[i];
            }
            for (int i = 1; i <= sumv; i++) {
                dp[i] = INF;
            }
            dp[0] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = sumv; j >=vi[i]; j--) {
                    dp[j] = Math.min(dp[j], dp[j-vi[i]] + wi[i]);
                }
            }
            int ans = 0;
            for (ans = sumv; ans >= 0; ans--) {
                if (w >= dp[ans]) break;
            }
            System.out.println(ans);
        }
        cin.close();
    }
}
