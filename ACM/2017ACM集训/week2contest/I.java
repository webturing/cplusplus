package week2contest;


import java.util.*;


class I {

    static int[] f;

    private static void Kruskal(List<Edge> list, int n) {

        int tot = 0;
        for (Edge e : list) {
            int s1 = find(e.u);
            int s2 = find(e.v);
            if (s1 != s2) {
                tot+=e.w;
                union(s1, s2);
            }
        }
        System.out.println(tot);
    }

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        ArrayList<Edge> list = new ArrayList<Edge>();
        int n = cin.nextInt();
        int m = cin.nextInt();
        for (int i = 0; i < m; i++)
            list.add(new Edge(cin.nextInt(), cin.nextInt(), cin.nextInt()));
        f = new int[n + 1];
        for (int i = 0; i <= n; i++)
            f[i] = i;
        int k = cin.nextInt();
        while (k-- > 0) union(cin.nextInt(),cin.nextInt());
        Collections.sort(list, Edge.inc);
        Kruskal(list, n);
        cin.close();

    }

    private static void union(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x != y) {
            f[x] = y;
        }
    }

    private static int find(int a) {
        return a == f[a] ? a : (f[a] = find(f[a]));
    }

    static class Edge {
        int u, v, w;
        Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }
        static Comparator<Edge> inc = new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return o1.w - o2.w;
            }
        };
    }
}
