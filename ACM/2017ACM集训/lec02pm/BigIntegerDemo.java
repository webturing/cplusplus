package lec02pm;

import java.math.BigInteger;

/**
 * Created by zj on 17-6-29.
 */
public class BigIntegerDemo {
    public static void main(String[] args) {
        BigInteger b=new BigInteger("111111111111111111111111111");
        BigInteger a=new BigInteger("111111111111111111111111111");
        System.out.println(a.add(b));
        System.out.println(a.subtract(b));
        System.out.println(a.multiply(b));
        System.out.println(a.isProbablePrime(10));
    }
}
