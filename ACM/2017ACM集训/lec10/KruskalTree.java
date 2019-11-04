package lec10;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;


class KruskalTree {


    private static void Kruskal(List<Edge> list, int[][] g) {


        int[] set = new int[g.length];
        for (int i = 0; i < g.length; i++)
            set[i] = i;
        for (Edge e : list) {
            int s1 = find(set, e.u);
            int s2 = find(set, e.v);
            if (s1 != s2) {
                System.out.println(e.u + " " + e.v + " " + e.w);
                union(set, s1, s2);
            }
        }
    }


    public static void main(String[] args) {

        int INF = Integer.MAX_VALUE;
        int[][] g = {
                {0, 6, 1, 5, INF, INF},
                {6, 0, 5, INF, 3, INF},
                {1, 5, 0, 5, 6, 4},
                {5, INF, 5, 0, INF, 2},
                {INF, 3, 6, INF, 0, 6},
                {INF, INF, 4, 2, 6, 0}};
        ArrayList<Edge> list = new ArrayList<>();

        for (int i = 0; i < g.length; i++)
                for (int j = 0; j < g.length; j++)
                if (g[i][j] != 0 && g[i][j] != INF)
                    list.add(new Edge(i, j, g[i][j]));
        Collections.sort(list, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return o1.w-o2.w;
            }
        });
//        for (Edge e : list) {
//            System.out.println(e.u+" "+e.v+" "+e.w);
//        }
        Kruskal(list, g);
    }


    private static void union(int[] f, int a, int b) {
        int x = find(f, a);
        int y = find(f, b);
        if (x != y) {
            f[x] = y;
        }
    }

    private static int find(int[] f, int a) {
        return a == f[a] ? a : (f[a] = find(f, f[a]));
    }

    static class Edge {
        int u, v, w;

        Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }
    }
}
