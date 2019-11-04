package lec02pm;

import java.math.BigInteger;

/**
 * Created by zj on 17-6-29.
 */
public class P1039 {
    public static void main(String[] args) {
        BigInteger prod=new BigInteger("1");
        for (int i = 2; i <=1997 ; i++) {
            prod=prod.multiply(new BigInteger(Integer.toString(i)));
        }
        System.out.println(prod);
    }
}
