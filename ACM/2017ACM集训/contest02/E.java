package contest02;


import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;


public class E {
	
	public static void main(String[] args) {
		
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {

			int[] a = new int[cin.nextInt()];
			for(int i =0;i<a.length;i++){
				a[i] = cin.nextInt();
			}
			TreeSet<Integer> set = new TreeSet<>();
			for(int i:a){
				set.add(i);
			}
			Object[] b = set.toArray();
			for(int i=0;i<a.length-1;i++){
				System.out.print(1+Arrays.binarySearch(b, a[i])+" ");
			}
			System.out.println(1+Arrays.binarySearch(b, a[a.length-1]));

		}
		cin.close();
		
	}
	
}
