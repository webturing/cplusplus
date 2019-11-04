package contest01;
import java.util.Scanner;

/**
 * Created by WebTuring on 2017-6-29.
 * 字符串
 * 异常处理
 */
public class B {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            String ip[] = cin.nextLine().split("\\.");
            System.out.println(check(ip) ? "Y" : "N");
        }
        cin.close();
    }

    private static boolean check(String[] ips) {
        for (String ip : ips)
            if (!check(ip))
                return false;
        return true;
    }

    private static boolean check(String ip) {
        try {
            int i = Integer.parseInt(ip);
            return i <= 255 && i >= 0;
        } catch (Exception e) {
            return false;
        }
    }
}
