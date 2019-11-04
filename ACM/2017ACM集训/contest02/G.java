package contest02;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/**
 * java codes from 陈善如
 */
public class G {
    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        int tot = cin.nextInt();
        while (tot-- > 0) {
            int n = cin.nextInt();
            ArrayList<Grade> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(new Grade(cin.nextInt(), cin.nextInt(), cin.nextInt()));
            }
            int t = cin.nextInt();
            Collections.sort(list, new Comparator<Grade>() {

                @Override
                public int compare(Grade o1, Grade o2) {
                    return (o1.getTa() - o1.getTc()) - (o2.getTa() - o2.getTc());
                }
            });
            int time = 0;
            for (Grade g : list) {
                time += g.getTc();
            }
            if (t < time) {
                System.out.println("Oh,my god!");
            } else if (t == time) {
                System.out.println("0");
            } else {
                int result = 0;
                t = t - time;
                for (Grade g : list) {
                    if (t >= (g.getTa() - g.getTc())) {
                        result++;
                        t -= (g.getTa() - g.getTc());
                    }
                }
                System.out.println(result);

            }

        }

        cin.close();
    }

    static class Grade {
        int ta;
        int tb;
        int tc;

        public Grade(int a, int b, int c) {
            ta = a;
            tb = b;
            tc = c;

        }

        public int getTa() {
            return ta;
        }

        public int getTb() {
            return tb;
        }

        public int getTc() {
            return tc;
        }

    }
}

