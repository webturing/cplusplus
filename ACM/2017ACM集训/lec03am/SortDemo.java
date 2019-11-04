package lec03am;

import java.util.Arrays;

/**
 * Created by zj on 17-6-30.
 */
public class SortDemo {
    public static void main(String[] args) {
        int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
        Arrays.sort(a);
        //for index
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
        //for each
        for (int i : a) {
            System.out.println(i);
        }
    }
}
