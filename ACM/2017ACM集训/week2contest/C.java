package week2contest;

/**
 * Created by fan on 2017/7/11.
 */
import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            int mp[][] = new int[n + 2][n + 2];
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= n; j++)
                    mp[i][j] = 0;
            while (cin.hasNext()) {
                int a = cin.nextInt(), b = cin.nextInt(), c = cin.nextInt();
                if (a == 0 && b == 0 && c == 0)
                    break;
                else
                    mp[a][b] = c;
            }
            int dp[][][][] = new int[n + 2][n + 2][n + 2][n + 2];

            int ans = solve(mp, dp, n);
            System.out.println(ans);

        }
        cin.close();
    }

    private static int solve(int[][] mp, int[][][][] dp, int n) {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                for (int i2 = 0; i <= n; i++)
                    for (int j2 = 0; j2 <= n; j2++)
                        dp[i][j][i2][j2] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int i2 = 1; i2 <= n; i2++)
                    for (int j2 = 1; j2 <= n; j2++) {
                        int tmp = Integer.MIN_VALUE;
                        tmp = Math.max(tmp, dp[i - 1][j][i2 - 1][j2]);
                        tmp = Math.max(tmp, dp[i - 1][j][i2][j2 - 1]);
                        tmp = Math.max(tmp, dp[i][j - 1][i2 - 1][j2]);
                        tmp = Math.max(tmp, dp[i][j - 1][i2][j2 - 1]);
                        if (i2 == i && j2 == j)
                            dp[i][j][i2][j2] = mp[i][j] + tmp;
                        else {
                            dp[i][j][i2][j2] = mp[i][j] + mp[i2][j2] + tmp;
                        }
                    }
        return dp[n][n][n][n];
    }
}
