package lec11;

import java.util.Scanner;

/**
 * Created by fan on 2017/7/12.
 */
public class DijkstraDemo {
    private static final int INF = Integer.MAX_VALUE;
    static boolean []vis; //判断顶点是否访问过，需要初始化
    static int [] dis; //保存从起点到编号为i的顶点的最短距离
    static int w[][]; // 边的价值，w[from][to]
    static int n, m; // m为边数，n为顶点数
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            n = cin.nextInt();
            m = cin.nextInt();
            w = new int[n+1][n+1];
            dis = new int[n+1];
            if (n == 0 && m == 0) break;

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    w[i][j] = INF;
                }
            }

            for (int i = 0; i < m; i++) {
               int from = cin.nextInt();
               int to = cin.nextInt();
               int cost = cin.nextInt();
               w[from][to] = w[to][from] = cost;
            }
            init(); //初始化
            dijkstra(1);
            System.out.println(dis[n]);
        }
        cin.close();
    }

    private static void init() {
        vis = new boolean[n+1];
        for (int i = 0; i <= n; i++) {
            vis[i] = false;
        }
    }

    private static void dijkstra(int start) {
        for (int i = 1; i <= n; i++) {
            dis[i] = (i == start) ? 0 : INF;
        }
        for (int i = 1; i <= n; i++) {
            int x = 0, min = INF;
            for (int j = 1; j <= n; j++) {
                if (!vis[j] && dis[j] < min) {
                    min = dis[x = j];
                }
            }
            vis[x] = true;
            for (int j = 1; j <= n; j++) {
                if (!vis[j] && dis[x] < INF && w[x][j] < INF)
                    dis[j] = Math.min(dis[j], dis[x] + w[x][j]);
            }
        }
    }
}
