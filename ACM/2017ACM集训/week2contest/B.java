package week2contest;

import java.util.Scanner;

/**
 * Created by fan on 2017/7/11.
 */
public class B {
    static char mp[][];
    static int n, m;
    static int dx[] = {-1, 0, 1, 0};
    static int dy[] = {0, -1, 0 ,1};

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        int index = 0;
        while (t-- > 0) {
            index++;
            n = cin.nextInt();
            m = cin.nextInt();
            mp = new char[n+2][m+2];
            for (int i = 0; i < m+2; i++) {
                mp[0][i] = '.';
                mp[n+1][i] = '.';
            }
            for (int i = 1; i <= n; i++) {
                mp[i] = ("." + cin.next() + ".").toCharArray();
            }
            dfs(0, 0);
            boolean isA = false;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <=m ; j++) {
                    if (mp[i][j] == '.') {
                        isA = true;
                        break;
                    }
                }
                if (isA)
                    break;
            }
            System.out.print("Case "+index+": ");
            if (isA)
                System.out.println("A");
            else
                System.out.println("H");
        }
        cin.close();
    }

    private static void dfs(int x, int y) {
        mp[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && nx < n + 2 && ny >= 0 && ny < m + 2 &&
                    mp[nx][ny] == '.')
                dfs(nx, ny);
        }
    }
}
