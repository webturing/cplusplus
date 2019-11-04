package contest10;

import java.util.Scanner;

/**
 * Created by fan on 2017/7/11.
 */
public class P2017 {
    private static final int INF = Integer.MAX_VALUE;
    static int w[][]; // 边的价值，w[from][to]
    static int n, m; // m为边数，n为顶点数
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            n = cin.nextInt();
            m = cin.nextInt();
            w = new int[n+1][n+1];
            if (n == 0 && m == 0) break;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    w[i][j] = (i == j) ? 0 : INF;
                }
            }
            for (int i = 0; i < m; i++) {
                int from = cin.nextInt();
                int to = cin.nextInt();
                int cost = cin.nextInt();
                if (cost < w[from][to])
                    w[from][to] = cost;
                if (cost < w[to][from])
                    w[to][from] = cost;
            }
            floyd();
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j < n; j++) {
                    System.out.print(w[i][j] + " ");
                }
                System.out.println(w[i][n]);
            }
        }
        cin.close();
    }

    private static void floyd() {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (w[i][k] < INF && w[k][j] < INF)
                        w[i][j] = Math.min(w[i][j], w[i][k] + w[k][j]);
                }
            }
        }
    }
}
