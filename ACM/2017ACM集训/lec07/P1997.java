package lec07;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class P1997 {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            int a[][] = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    a[i][j] = cin.nextInt();

            bfs(a, n);
        }
        cin.close();
    }

    private static void bfs(int[][] a, int n) {
        int vi[][] = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                vi[i][j] = 0;
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};
        Queue<Point> qu = new LinkedList<>();
        qu.offer(new Point(0, 0));
        while (qu.peek() != null) {
            Point p = qu.poll();
            if (vi[p.x][p.y] == 0) {
                System.out.print(a[p.x][p.y] + " ");
                vi[p.x][p.y] = 1;

                for (int i = 0; i < 4; i++) {
                    int nx = p.x + dx[i];
                    int ny = p.y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && vi[nx][ny] == 0) {
                        qu.offer(new Point(nx,ny));
                    }
                }
            }
        }
        System.out.println();
    }

    static class Point {
        int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

}
