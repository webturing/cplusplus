package luogu;

import java
.math.
BigInteger;
import java
.util.
Scanner;

public

class B_P1018_乘积最大 {
public

    static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        int k = cin.nextInt();
        String s = cin.next();
        System.out.println(dfs(s, k));
    }

private

    static BigInteger dfs(String s, int k) {
        if (k == 0) {
            return new BigInteger(s);
        }

        if (k == s.length() - 1) {
            BigInteger ret = BigInteger.ONE;
            for (int i = 0; i < s.length(); i++) {
                ret = ret.multiply(new BigInteger(s.substring(i, i + 1)));
            }
            return ret;
        }

        BigInteger max = BigInteger.ONE;
        for (int i = 1; i < s.length() - k; i++) {
            BigInteger
            ret = new BigInteger(s.substring(0, i)).multiply(dfs(s.substring(i, s.length()), k - 1));
            if (max.compareTo(ret) < 0) {
                max = ret;
            }
        }
        return max;
    }
}
