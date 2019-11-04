package lec01;

public class AAddB {
    public static void main(String[] args) {
        java.util.Scanner s = new java.util.Scanner(System.in);
        int a = s.nextInt();
        int b = s.nextInt();
        System.out.println(a + b);
        s.close();
    }
}
