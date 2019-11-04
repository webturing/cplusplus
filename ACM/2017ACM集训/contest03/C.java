package contest03;

/*
    Date: Sat Jul 01 2017 19:56:25 GMT+0800 (CST)
    Author: 1884140210
*/
import java.util.Scanner;

/**
 * Created by fan on 17-7-1.
 */
public class C {
    static  int pri[] = new int[3600];
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            System.out.print(n+"=");
            init();
            if (n < 2) {
                System.out.print(n);
            }else {
                for (int i = 0; i <= 3600; i++) {
                    if (n % pri[i] == 0) {
                        System.out.print(pri[i]);
                        n /= pri[i];
                        break;
                    }
                }
                for (int i = 0; i < 3600; ) {
                    if (n % pri[i] == 0) {
                        System.out.print("*" + pri[i]);
                        n /= pri[i];
                    }else i++;
                }

            }
            System.out.println();
        }
        cin.close();
    }

    private static void init() {
        int index = 0;
        for (int i=2; index < 3600; i++) {
            if (isPrime(i))
                pri[index++] = i;

        }
    }

    private static boolean isPrime(int n) {
        if (n < 2) return false;
        if (n % 2 == 0 && n != 2) return false;
        for (int i=3; i*i<=n; i+=2)
            if (n % i == 0)
                return false;
        return true;
    }
}
