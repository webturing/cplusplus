package contest05;

import java.util.Scanner;

/**
 * Created by fan on 2017/7/5.
 */
public class C {
    static int N, M;
    static char [][]mp;
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            N = cin.nextInt();
            M = cin.nextInt();
            mp = new char[N][M];
            for (int i=0; i<N; i++) {
                mp[i] = cin.next().toCharArray();
            }
            int ans = 0;
            for (int i=0; i<N; i++) {
                for (int j=0; j<M; j++) {
                    if (mp[i][j] == '.')
                        ans = Math.max(ans, f(i, j));
                }
            }
            System.out.println(ans);
        }
        cin.close();
    }

    private static int f(int x, int y) {
        int t = x;
        int cnt = 0;
        while (--t >= 0) {
            if (mp[t][y] == '#') break;
            if (mp[t][y] == 'G') cnt++;
        }
        t = x;
        while (++t < N) {
            if (mp[t][y] == '#') break;
            if (mp[t][y] == 'G') cnt++;
        }
        t = y;
        while (--t >= 0) {
            if (mp[x][t] == '#') break;
            if (mp[x][t] == 'G') cnt++;
        }
        t = y;
        while (++t < M) {
            if (mp[x][t] == '#') break;
            if (mp[x][t] == 'G') cnt++;
        }
        return cnt;
    }
}
