package lec02;
import java.util.Arrays;

/**
 * Created by zj on 17-6-29.
 */
public class ArrayDemo4 {
    public static void main(String[] args) {
        int a[]=new int[10];
        System.out.println(Arrays.toString(a));
        //Arrays.fill(a,1);
        Arrays.fill(a,0,a.length/2,1);
        System.out.println(Arrays.toString(a));
        int b[]=new int[5];
        for (int i = 0; i < b.length; i++) {
         //   b[i]=a[i];
        }
        System.arraycopy(a,0,b,0,a.length/2);
        System.out.println(Arrays.toString(b));
    }
}
