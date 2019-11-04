package contest02;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class D {
	
	public static void main(String[] args) {
		
		Scanner cin = new Scanner(System.in);
		while(cin.hasNextLine()){
			cin.nextLine();
			String[] nums = cin.nextLine().split("\\s+");
			LinkedList<String> list = new LinkedList<>();
			list.addAll(Arrays.asList(nums));
			while(list.size()>0){
				System.out.print(list.get(0)+" ");
				list.remove(0);
				if(list.size()==0){
					break;
				}
				list.add(list.size(),list.get(0));
				list.remove(0);
			}
	
		}
		

		cin.close();
		
	}
	
}
