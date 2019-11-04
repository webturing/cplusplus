package contest09;


import java.util.*;


class A {


    private static void Kruskal(List<Edge> list, int n, List<Edge> ans) {

        int[] set = new int[n + 1];
        for (int i = 0; i <= n; i++)
            set[i] = i;
        for (Edge e : list) {
            int s1 = find(set, e.u);
            int s2 = find(set, e.v);
            if (s1 != s2) {
                //System.out.println(e.u+" "+e.v+" "+e.w);
                ans.add(e);
                union(set, s1, s2);
            }
        }
    }


    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        ArrayList<Edge> list = new ArrayList<Edge>();
        ArrayList<Edge> ans = new ArrayList<Edge>();
        int n = cin.nextInt();
        int m = cin.nextInt();
        for (int i = 0; i < m; i++) {
            list.add(new Edge(cin.nextInt(), cin.nextInt(), cin.nextInt()));
        }
        Collections.sort(list, Edge.inc);
        Kruskal(list, n, ans);
        Collections.sort(ans, Edge.cmp);
        int tot=0;
        for (Edge e : ans) {
            tot+=e.w;
        }
        System.out.println(tot);
        for (Edge e : ans) {
            System.out.println(e.u + " " + e.v);
        }
        cin.close();
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

        static Comparator<Edge> inc = new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                if(o1.w!=o2.w){
                    return o1.w - o2.w;
                }

                if(o1.u!=o2.u){
                    return o1.u-o2.u;
                }
                return o1.v-o2.v;
            }
        };
        static Comparator<Edge> cmp = new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                if (o1.u != o2.u)
                    return o1.u - o2.u;
                return o1.v - o2.v;
            }
        };

    }
}
