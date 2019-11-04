package contest02;

import java.util.Scanner;

public class C {
	
	public static void main(String[] args) {
		
		Scanner cin = new Scanner(System.in);
		
		while(cin.hasNextLine()){
			
			String[] words = cin.nextLine().split("\\s+");
			
			int max = 0;
			
			for(int i=0;i<words.length;i++){
				if(words[max].length()<words[i].length())
					max=i;
			}
			System.out.println(words[max]);
			
			
		}

		cin.close();
	}
	
	
}
