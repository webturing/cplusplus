package lec02;
import java.util.Arrays;

/**
 * Created by zj on 17-6-28.
 */
public class ArraysDemo3 {
    public static void main(String[] args) {
        int[] a={1,2,3,4,5,6,7,8};
        System.out.println(a);
        String s= Arrays.toString(a).replaceAll(",","");

        System.out.println(s.substring(1,s.length()-1));
        System.out.println("abcdefg".substring(1,5));
        System.out.println("abcdefg".substring(2));



    }
}
