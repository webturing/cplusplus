package contest01;
import java.util.Scanner;

/**
 * Created by WebTuring on 2017-6-29.
 * 数组模拟
 */
public class A {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        while (cin.hasNext()) {
            int[] freq = new int[10];
            int n = cin.nextInt();
            for (int i = 1; i <= n; i++) {
                for (int j = i; j > 0; j /= 10)
                    freq[j % 10]++;
            }
            for (int i : freq)
                System.out.println(i);
        }
        cin.close();
    }
}
