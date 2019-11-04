package lec01;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by zj on 17-6-28.
 * 1. Input(Scanner) & Output(String.format)
 * 2. Math.sqrt()
 */
public class P1274 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        int a[] = new int[3];
        a[0] = cin.nextInt();
        a[1] = cin.nextInt();
        a[2] = cin.nextInt();

//        for (int i = 0; i < a.length; i++) {
//            a[i]=cin.nextInt();
//        }
        Arrays.sort(a);
        System.out.println(String.format("%d %d %d", a[0], a[1], a[2]));

        cin.close();

    }

}
