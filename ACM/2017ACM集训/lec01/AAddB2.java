package lec01;
import java.util.Scanner;

public class AAddB2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int b = s.nextInt();
        System.out.println(a + b);
        s.close();
    }
}
