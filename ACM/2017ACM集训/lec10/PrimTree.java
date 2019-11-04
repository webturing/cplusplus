package lec10;

import java.util.Scanner;


public class PrimTree {

    private static int INF = Integer.MAX_VALUE;

    private static void Prim(int[][] g,int v){
        int n = g[0].length;
        int[] low = new int[n];
        int min,k=0;
        int[] clo = new int[n];
        for (int i = 0; i < n; i++) {
            low[i] = g[v][i];
            clo[i] = v;
        }
        for (int i = 1; i < n; i++) {

            min = INF;
            for (int j = 0; j < n; j++) {
                if(low[j]!=0&&low[j]<min){
                    min = low[j];
                    k=j;
                }
            }
            System.out.println(clo[k]+" "+k+" "+min);
            low[k]=0;
            for (int j = 0; j <n ; j++) {
                if(g[k][j]!=0&&g[k][j]<low[j]){
                    low[j] = g[k][j];
                    clo[j]=k;
                }
            }
        }
    }

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);

        int[][] G = {
                {0,6,1,5,INF,INF},
                {6,0,5,INF,3,INF},
                {1,5,0,5,6,4},
                {5,INF,5,0,INF,2},
                {INF,3,6,INF,0,6},
                {INF,INF,4,2,6,0}};

        Prim(G,0);

        cin.close();
    }
}
