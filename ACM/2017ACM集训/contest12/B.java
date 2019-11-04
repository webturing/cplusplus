package contest12;

import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            int m = cin.nextInt();
            int s = cin.nextInt();
            LinkedList<Ran> list = new LinkedList<>();
            PriorityQueue<Ran> qu = new PriorityQueue<>(Ran.inc);
            for (int i = 0; i < m; i++)
                list.add(new Ran(cin.nextInt(), cin.nextInt()));
            int ans = 0;

            while (s < n && list.size() > 0) {
                for (int i = 0; i < list.size(); i++) {
                    Ran r = list.get(i);
                    if (s >= r.x) {
                        qu.add(r);
                        list.remove(i);
                        i--;
                    }
                }
                if (qu.peek() == null)
                    break;
                else {
                    s += qu.poll().s;
                    ans++;
                }
            }
            System.out.println(s >= n ? ans : -1);
        }
        cin.close();
    }

    static class Ran {
        int x;
        int s;

        Ran(int x, int s) {
            this.x = x;
            this.s = s;
        }
        static Comparator<Ran> inc = new Comparator<Ran>() {
            @Override
            public int compare(Ran o1, Ran o2) {
                return o2.s - o1.s;
            }
        };
    }
}
