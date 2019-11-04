package lec02pm;

import java.math.BigDecimal;
import java.util.Scanner;

/**
 * Created by zj on 17-6-29.
 */
public class P1298 {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext()){
            int a=cin.nextInt();
            int b=cin.nextInt();
            int c=cin.nextInt();

            BigDecimal ba=new BigDecimal(Integer.toString(a));
            BigDecimal bb=new BigDecimal(Integer.toString(b));
            BigDecimal bc=ba.divide(bb,c,BigDecimal.ROUND_UP);
            System.out.println(bc.toString());
        }
        cin.close();
    }
}
