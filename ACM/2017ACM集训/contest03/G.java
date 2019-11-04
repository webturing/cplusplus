package contest03;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 * Created by fan on 17-7-1.
 */
public class G {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            J []j = new J[n];
            for (int i=0; i<n; i++) {
                j[i] = new J(cin.nextInt(), cin.nextInt());
            }
            Arrays.sort(j, new Comparator<J>() {
                @Override
                public int compare(J o1, J o2) {
                    return o1.end - o2.end;
                }
            });
            int cnt = 0;
            int now = j[0].end;
            for (int i=1; i<n; i++) {
                if (j[i].start > now) {
                    cnt++;
                    now = j[i].end;
                }
            }
            System.out.println(n - cnt);
        }
        cin.close();
    }
    static class J{
        int start, end;

        public J(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}
