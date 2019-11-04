package contest02;

import java.util.Scanner;


public class F {

	public static void main(String[] args) {

		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {

			char[] a = cin.next().toCharArray();
			int k = cin.nextInt();
			for (int i = 0; i < a.length && k > 0; i++) {

				int index = i;
				char max = a[i];
				for (int j = i + 1; j <= i + k && j < a.length; j++) {
					if (max < a[j]) {
						max = a[j];
						index = j;
					}
				}
				if (index != i) {
					for(int j = index;j>i;j--){
						char temp = a[j];
						a[j] = a[j-1];
						a[j-1] = temp;
					}
					k-=index-i;
				}

			}
			for(int i=0;i<a.length;i++){
				System.out.print(a[i]);
			}
			System.out.println();

		}

		cin.close();
	}

}
