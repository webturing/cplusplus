package contest01;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class F {
    static Scanner cin = new Scanner(System.in);
    static PrintWriter cout = new PrintWriter(System.out);


    public static void main(String[] args) {
        for (int n = cin.nextInt(); n-- > 0; ) {
            if (foo(cin.next()).equals(foo(cin.next())))
                cout.println("Yes");
            else
                cout.println("No");
        }
        cout.close();
        cin.close();
    }

    private static TreeSet<String> foo(String s) {
        TreeSet<String> set = new TreeSet<>();
        set.addAll(Arrays.asList(s.split("")));
        return set;
    }


}
