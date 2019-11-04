package contest02;

import java.math.BigInteger;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			int n = cin.nextInt();
			BigInteger ans = BigInteger.ONE;
			for(int i=1;i<=n;i++){
				ans = ans.multiply(BigInteger.valueOf(i));					
			}
			System.out.println(ans);
		}
		
		cin.close();
	}

}
