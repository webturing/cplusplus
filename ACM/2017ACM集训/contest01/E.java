package contest01;

import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeSet;

/**
 * 集合操作
 */
public class E {
    static Scanner cin = new Scanner(System.in);
    static PrintWriter cout = new PrintWriter(System.out);

    public static void main(String[] args) {
        while (cin.hasNext()) {
            int n = cin.nextInt();
            if (n == 0) break;
            TreeSet<Integer> set = new TreeSet<Integer>();
            for (int i = 0; i < n; i++) set.add(cin.nextInt());
            cout.println(set.size());
            String s = set.toString();
            cout.println(s.substring(1, s.length() - 1).replaceAll(",", ""));
        }

        cout.close();
        cin.close();
    }


}
