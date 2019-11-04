package lec03am;

import java.util.Arrays;
import java.util.Collections;

/**
 * Created by zj on 17-6-30.
 */
public class SortDemo2 {
    public static void main(String[] args) {
        Integer a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
        Arrays.sort(a);
        System.out.println(Arrays.toString(a));
        Arrays.sort(a, Collections.reverseOrder());
        System.out.println(Arrays.toString(a));
    }
}
