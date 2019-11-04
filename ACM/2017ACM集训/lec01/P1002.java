package lec01;
import java.util.Scanner;

/**
 * Created by zj on 17-6-28.
 * 1. Input(Scanner) & Output(String.format)
 * 2. Math.sqrt()
 */
public class P1002 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        double a = cin.nextDouble();
        double b = cin.nextDouble();
        double c = cin.nextDouble();

        double delta = Math.sqrt(b * b - 4 * a * c);
        double x1 = (-b + delta) / 2 / (a);
        double x2 = (-b - delta) / 2 / (a);
        if (x1 < x2) {
            double t = x1;
            x1 = x2;
            x2 = t;
        }
        System.out.println(String.format("%.2f %.2f", x1, x2));
        cin.close();
    }
}
