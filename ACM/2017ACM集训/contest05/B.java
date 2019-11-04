package contest05;

import java.util.Scanner;

/**
 * Created by fan on 2017/7/5.
 */
public class B {
    static int father[], cnt;
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int N = cin.nextInt(), M = cin.nextInt();
            if (N == 0 && M == 0) break;
            init(N);
            for (int i=0; i<M; i++) {
                int a = cin.nextInt(), b = cin.nextInt();
                union(a, b);
            }
            System.out.println(cnt-1);
        }
        cin.close();
    }

    private static void union(int a, int b) {
        int p = find(a);
        int q = find(b);
        if (p == q)
            return;
        father[p] = q;
        cnt--;
    }

    private static int find(int x) {
        return x == father[x] ? x : (father[x] = find(father[x]));
    }

    private static void init(int n) {
        cnt = n;
        father = new int[n+1];
        for (int i=0; i<=n; i++)
            father[i] = i;
    }
}
