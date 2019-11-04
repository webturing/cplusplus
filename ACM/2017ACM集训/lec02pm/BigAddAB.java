package lec02pm;

import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by zj on 17-6-29.
 */
public class BigAddAB {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        BigInteger a=new BigInteger(cin.next());
        BigInteger b=cin.nextBigInteger();
        System.out.println(a.multiply(b));
        cin.close();

    }
}
