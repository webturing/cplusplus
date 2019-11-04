package week2contest;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class H {

    private static int map[][];
    private static int n,m;
    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt();
        m = cin.nextInt();
        map = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j <m ; j++)
                map[i][j] = cin.nextInt();
        bfs(0, 0);
        cin.close();
    }

    private static void bfs(int x, int y) {
        int ans = Integer.MAX_VALUE;
        int flag = 0;
        LinkedList<Point> road = new LinkedList<>();
        Queue<Point> qu = new LinkedList<>();
        int[][] vi = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vi[i][j] = 0;
        qu.offer(new Point(x, y, 0));
        while (qu.peek() != null) {
            Point cur = qu.poll();
            if(vi[cur.x][cur.y] == 1) continue;
            else road.add(new Point(cur.x,cur.y,cur.s,cur.px,cur.py));
            if (cur.x == 4 && cur.y == 4){
                if((ans = Math.min(ans,cur.s))==cur.s)
                    flag = road.size() - 1;
            } else vi[cur.x][cur.y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && map[nx][ny] != -1 && vi[nx][ny] == 0)
                    qu.offer(new Point(nx, ny,cur.s + 1, cur.x, cur.y));
            }
        }
        Point e = road.get(flag);
        LinkedList<Point> reRoad = new LinkedList<>();
        while(e.px!=-1){
            for (Point p : road) {
                if(e.px==p.x&&e.py==p.y){
                    reRoad.add(new Point(e.x,e.y,0));
                    e = p;
                    break;
                }
            }
        }
        reRoad.add(new Point(0,0,0));
        for (int i = reRoad.size()-1; i >=1 ; i--) {
            Point p = reRoad.get(i);
            System.out.print(map[p.x][p.y]+"->");
        }
        Point p = reRoad.get(0);
        System.out.println(map[p.x][p.y]);
    }
    static class Point {
        int x, y, s;
        int px, py;
        Point(int x, int y, int s) {
            this.x = x;
            this.y = y;
            this.s = s;
            this.px = -1;
            this.py = -1;
        }
        Point(int x, int y, int s, int px, int py) {
            this.x = x;
            this.y = y;
            this.s = s;
            this.px = px;
            this.py = py;
        }
    }
}


