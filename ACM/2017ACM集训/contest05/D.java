package contest05;

import java.util.Scanner;

/**
 * Created by fan on 2017/7/5.
 */
public class D {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int N = cin.nextInt();
            Weibo weibo[] = new Weibo[N];
            for (int i=0; i<N; i++)
                weibo[i] = new Weibo(cin.next());
            int M = cin.nextInt();
            for (int i=0; i<M; i++) {
                String a = cin.next();
                cin.next();
                String b = cin.next();
                if (a.equals(b)) continue;
                for (int j=0; j<N; j++) {
                    if (weibo[j].name.equals(a)) {
                        weibo[j].have++;
                    }
                    if (weibo[j].name.equals(b)) {
                        weibo[j].to++;
                    }
                }
            }
            for (int i=0; i<N; i++) {
                System.out.println(weibo[i].name+" "+weibo[i].to+" "+weibo[i].have);
            }
            System.out.println();
        }
        cin.close();
    }
    static class Weibo {
        String name;
        int have;
        int to;
        public Weibo(String name) {
            this.name = name;
        }
    }
}
