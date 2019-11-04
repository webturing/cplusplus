package lec06;

import java.util.Scanner;

/**
 * Created by fan on 2017/7/5.
 */
public class P1944 {
    static int N, M, sx, sy, ex, ey, ans;
    static char [][]mp;
    static int dx[] = {-1, 0, 1, 0};
    static int dy[] = {0, -1, 0, 1};
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        N = cin.nextInt();
        M = cin.nextInt();
        mp = new char[N][M];
        for (int i=0; i<N; i++) {
            String s = cin.next().trim();
            if (s.contains("S")) {
                sx = i;
                sy = s.indexOf('S');
            }
            if (s.contains("G")) {
                ex = i;
                ey = s.indexOf('G');
            }
            mp[i] = s.toCharArray();
        }
        int step = 0;
        ans = Integer.MAX_VALUE;
        dfs(sx, sy, step);
        System.out.println(ans);
        cin.close();
    }

    private static void dfs(int x, int y, int step) {
        if (x == ex && y == ey) {
            ans = Math.min(ans, step);
            return;
        }
        mp[x][y] = '#';
        for (int i=0; i<4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && mp[nx][ny] != '#')
                dfs(nx, ny, step + 1);
        }
    }
}
