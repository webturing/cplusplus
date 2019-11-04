package contest03;
import java.util.Scanner;

/**
 * Created by fan on 17-7-1.
 */
public class E {
    static int a[] = new int[43454];

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int b[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
        for (int i = 0; i < b.length; i++)
            a[i] = b[i];

        for (int i = 1; i < 300; i++) {
            for (int j = 0; j < 10; j++) {
                a[i * 10 + j] = a[i] + a[j];
            }
        }

        while (cin.hasNext()) {
            int n = cin.nextInt();
            int cnt = 0;
            for (int i = 0; i < 1000; i++) {
                for (int j = 0; j < 1000; j++) {
                    if (a[i] + a[j] + a[i + j] + 4 == n) {
                        cnt++;
                    }
                }
            }
            System.out.println(cnt);
        }
        cin.close();
    }
}
