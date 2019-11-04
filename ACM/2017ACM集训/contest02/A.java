package contest02;

import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class A {

	
	public static void main(String[] args) {
		
		Scanner cin = new Scanner(System.in);
		String[] words = cin.nextLine().split("\\s+");
		TreeSet<String> set = new TreeSet<>();
		set.addAll(Arrays.asList(words));
		System.out.println(set.size());
		cin.close();
	}
	
	
}