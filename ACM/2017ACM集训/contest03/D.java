package contest03;

/*
    Date: Sat Jul 01 2017 19:07:14 GMT+0800 (CST)
    Author: 1884140210
*/
import java.util.Scanner;

/**
 * Created by fan on 17-7-1.
 */
public class D {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNextLine()) {
            String s = cin.nextLine();
            int i = Integer.parseInt(s.substring(0,3));
            String b = s.substring(3, s.indexOf("|"));
            String c = s.substring(s.indexOf("|")+1);
            double d = Double.parseDouble(b);
            System.out.printf("%-8d|%8.1f|%s", i, d, c);
        }
        cin.close();
    }
}
