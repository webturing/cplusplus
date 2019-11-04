package week2contest;

/**
 * Created by fan on 2017/7/11.
 */
import java.util.Scanner;

public class E {
    static int fa[], n, ans, m;
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        for (int cas = 1; cas <= t; cas++) {
            System.out.print("Case #"+cas+": ");
            n = cin.nextInt();
            m = cin.nextInt();
            init();
            for (int i=0; i<m; i++) {
                int x = cin.nextInt(), y = cin.nextInt();
                if (same(x, y)) {
                    ans++;
                }else{
                    union(x, y + n);
                    union(x + n, y);
                }
            }
            System.out.println(ans);
        }
        cin.close();
    }

    private static void union(int x, int y) {
        int p = find(x);
        int q = find(y);
        if (p == q)return;
        fa[p] = q;
    }

    private static boolean same(int x, int y) {
        return find(x) == find(y);
    }

    private static int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    private static void init() {
        ans = 0;
        fa = new int[n*n+1];
        for (int i=0; i<= n * n; i++)
            fa[i] = i;
    }
}
