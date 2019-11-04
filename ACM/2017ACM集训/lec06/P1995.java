package lec06;

import java.util.Scanner;

/**
 * Created by fan on 2017/7/5.
 */
public class P1995 {
    static int father[], total;
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt(), m = cin.nextInt();
            init(n);
            for (int i=0; i<m; i++) {
                union(cin.nextInt(), cin.nextInt());
            }
            System.out.println(total);
            for(int i=1;i<=n;i++)
                System.out.printf("%d ",father[i]);
        }
        cin.close();
    }

    private static void union(int x, int y) {
        int p = find(x);
        int q = find(y);
        if (p == q)
            return;
        father[q] = p;
        total--;
    }

    private static int find(int x) {
        return x == father[x] ? x : (father[x] = find(father[x]));
    }

    private static void init(int n) {
        total = n;
        father = new int[n+1];
        for (int i=0; i<=n; i++)
            father[i] = i;
    }
}
