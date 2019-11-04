package lec03am;

import java.util.Vector;

/**
 * Created by zj on 17-6-30.
 */
public class VectorDemo {
    public static void main(String[] args) {
        Vector<Integer> v = new Vector<Integer>();
        for (int i = 0; i < 10; i++) {
            v.add(i);
            // System.out.println(v);
        }
        System.out.println(v.get(5));
        System.out.println(v.size());
        System.out.println(v);
        for (int i = 0; i < v.size(); i++) {
            v.get(i);
            v.set(i, i * i);
        }
        for (Integer i : v) {

        }

    }
}
