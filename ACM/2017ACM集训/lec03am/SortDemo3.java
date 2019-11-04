package lec03am;

import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by zj on 17-6-30.
 */
public class SortDemo3 {
    public static void main(String[] args) {
        String[] words = "to know everything is to know nothing".split(" ");
        System.out.println(Arrays.toString(words));
        // Arrays.sort(words);
        System.out.println(Arrays.toString(words));
        Arrays.sort(words, new Comparator<String>() {
                    public int compare(String sa, String sb) {
                        int cmp = sa.length() - sb.length();
                        if (cmp != 0) return cmp;
                        return sa.compareTo(sb);
                    }
                }
        );
        System.out.println(Arrays.toString(words));
    }
}
