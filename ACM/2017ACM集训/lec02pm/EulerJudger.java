package lec02pm;

import java.math.BigInteger;

/**
 * Created by zj on 17-6-29.
 */
public class EulerJudger {
    static BigInteger f(int n)
    {
        BigInteger two=new BigInteger("2");
        BigInteger ans=two.pow(1<<n).add(BigInteger.ONE);
        return ans;

    }
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            System.out.println(f(i).isProbablePrime(100));
        }
    }
}
