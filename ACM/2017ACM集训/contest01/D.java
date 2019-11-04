package contest01;
import java.util.Scanner;

/**
 * Created by WebTuring on 2017-6-29.
 * 字符串处理
 */
public class D {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNextLine()) {
            char cs[] = cin.nextLine().toCharArray();
            if (Character.isLetter(cs[0])) cs[0] = Character.toUpperCase(cs[0]);
            for (int i = 1; i < cs.length; i++) {
                if (!Character.isLetter(cs[i - 1]) && Character.isLetter(cs[i])) {
                    cs[i] = Character.toUpperCase(cs[i]);
                }
            }
            System.out.println(new String(cs));
        }
        cin.close();
    }
}
