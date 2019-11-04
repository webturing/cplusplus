package contest04;

import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by fjinh on 2017/7/2.
 */
public class D {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            String n = cin.next();
            int k = cin.nextInt();
            while (k-- > 0) {
                n = remove(n);
            }
            System.out.println(n);
        }
        cin.close();
    }

    private static String remove(String n) {
        char a[] = n.toCharArray();
        int index = a.length - 1;
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i + 1]) {
                index = i;
                break;
            }
        }
        return new BigInteger(new StringBuffer(n).deleteCharAt(index).toString()).toString();
    }
}
