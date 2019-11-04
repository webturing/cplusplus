package lec01;
import java.util.Arrays;

/**
 * Created by zj on 17-6-28.
 */
public class ArraysDemo {
    public static void main(String[] args) {
        int[] a = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
        System.out.println(a[0]);
        System.out.println(a.length);//10
        System.out.println(a[a.length - 1]);
        for (int i : a) {
            System.out.println(i);

        }
        Arrays.sort(a);
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]);
        }
    }
}
