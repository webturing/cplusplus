package lec02;
import java.util.Arrays;

/**
 * Created by zj on 17-6-29.
 */
public class ArrayAlgorithm {
    public static void main(String[] args) {
        int a[]={1,3,5,7,9,2,4,6,8,0};
        int k=13;
        int index=find(a,k);
        System.out.println(index);
        Arrays.sort(a);
        int index2= Arrays.binarySearch(a,0);
        System.out.println(index2);
    }

    private static int find(int[] a, int k) {

        for (int i = 0; i < a.length; i++) {
                if(k==a[i])
                    return i;
        }
        return -1;
    }
}
