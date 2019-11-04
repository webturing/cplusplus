package contest05;

import java.util.Scanner;

/**
 * Created by fan on 2017/7/5.
 */
public class A {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        while (t-- > 0) {
            int N = cin.nextInt();
            int [][] a = new int[N+1][N+1];
            for (int i=1; i<=N; i++) {
                for (int j=1; j<=i; j++) {
                    a[i][j] = cin.nextInt();
                }
            }
            int [][]dp = new int[N+1][N+1];

            for (int i=1; i<=N; i++) {
                dp[N][i] = a[N][i];
            }
            for (int i=N-1; i>=1; i--) {
                for (int j=1; j<=i; j++) {
                    dp[i][j] = a[i][j] + Math.max(dp[i+1][j], dp[i+1][j+1]);
                }
            }
            System.out.println(dp[1][1]);
        }
        cin.close();
    }
}
