package contest10;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by fan on 2017/7/12.
 */
public class P2018 {
    private static final int INF = Integer.MAX_VALUE;
    static boolean []vis; //判断顶点是否访问过，需要初始化
    static int [] dis; //保存从起点到编号为i的顶点的最短距离
    static int w[][]; // 边的价值，w[from][to]
    static int n, m; // m为边数，n为顶点数
    static int path[]; // 记录上一个点的路径
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            n = cin.nextInt();
            m = cin.nextInt();
            w = new int[n+1][n+1];
            dis = new int[n+1];
            path = new int[n+1];
            for (int i = 0; i <= n; i++) {
                path[i] = i;
            }
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
            path[1] = 0;

            System.out.println(dis[n]);
            findPath();
        }
        cin.close();
    }

    private static void findPath() {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(n);
        int t = path[n];
        while (t != 1) {
            list.add(t);
            t = path[t];
        }
        System.out.print("1");
        for (int i=list.size()-1; i>=0; i--){
            System.out.print("->"+list.get(i));
        }
        System.out.println();
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
        for (int i = 1; i <= n; i++) {//x为未访问过的d[i]存在最小值的那个顶点编号，每次都需要找这个顶点，找n次
            int x = 0, min = INF;
            for (int j = 1; j <= n; j++) {
                if (!vis[j] && dis[j] < min) {
                    min = dis[x = j];
                }
            }
            vis[x] = true;
            for (int j = 1; j <= n; j++) {
                if (!vis[j] && dis[x] < INF && w[x][j] < INF
                        && dis[j] > dis[x] + w[x][j]) {
                    dis[j] = dis[x] + w[x][j];
                    path[j] = x;
                }
            }
        }
    }
}
