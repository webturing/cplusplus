package lec15;


import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;

/**
 * Created by fan on 2017/7/16.
 */

public class ToposortDemo {
    static int du[], n, m, L[];
    static Vector<Integer> g[];
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            n = cin.nextInt(); m = cin.nextInt();
            g = new Vector[n+1];
            for (int i = 0; i <= n; i++) {
                g[i] = new Vector<>();
            }
            for (int i = 0; i < m; i++) {
                int x = cin.nextInt();
                int y = cin.nextInt();
                g[x].addElement(y);
            }
            if (toposort()) {
                for (int i = 0; i < n-1; i++) {
                    System.out.print(L[i] + " ");
                }
                System.out.println(L[n-1]);
            }else {
                System.out.println("-1");
            }
        }
        cin.close();
    }

    private static boolean toposort() {
        du = new int[n+1];
        L = new int[n];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                du[g[i].get(j)]++;
            }
        }
        int tot = 0;
        Queue<Integer> Q = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            if (du[i] == 0)
                Q.add(i);
        }

        while (Q.peek() != null) {
            int x = Q.poll();
            L[tot++] = x;
            for (int i = 0; i < g[x].size(); i++) {
                int t = g[x].get(i);
                du[t]--;
                if (du[t] == 0)
                    Q.add(t);
            }
        }

        if (tot == n)
            return true;
        return false;
    }
}
