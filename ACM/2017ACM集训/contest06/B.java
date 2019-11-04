package contest06;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * Created by chshru on 2017/7/6.
 */
public class B {

    private static char map[][];
    private static int vi[][];
    private static int ans = 0xffffff;
    private static int n, m, sx, sy, ex, ey;
    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            n = cin.nextInt();
            m = cin.nextInt();
            if (n == 0 && m == 0) break;
            map = new char[n][m];
            vi = new int[n][m];
            for (int i = 0; i < n; i++)
                map[i] = cin.next().trim().toCharArray();
            init();
            if (bfs(sx, sy)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }

        }
        cin.close();
    }

    private static void init() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                vi[i][j] = 0;
                if (map[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if (map[i][j] == 'G') {
                    ex = i;
                    ey = j;
                }
            }
    }

    private static boolean bfs(int x, int y) {

        Queue<Poin> qu = new LinkedList<>();
        qu.offer(new Poin(x, y, 0));
        while (qu.peek() != null) {
            Poin cur = qu.poll();
            if (cur.x == ex && cur.y == ey) return true;
            vi[cur.x][cur.y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && map[nx][ny] != '#' && vi[nx][ny] == 0)
                    qu.offer(new Poin(nx, ny, cur.s + 1));
            }
        }
        return false;
    }
}

class Poin {
    int x, y, s;

    Poin(int x, int y, int s) {
        this.x = x;
        this.y = y;
        this.s = s;
    }
}