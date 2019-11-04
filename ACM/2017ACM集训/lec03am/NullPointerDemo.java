package lec03am;

/**
 * Created by zj on 17-6-30.
 */
public class NullPointerDemo {
    public static void main(String[] args) {
        String a[] = new String[10];
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]);
        }
        System.out.println(a[0].length());
    }
}
