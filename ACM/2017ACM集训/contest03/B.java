package contest03;

import java.util.Comparator;
import java.util.Scanner;

/**
 * Created by fan on 17-7-1.
 */
import java.util.ArrayList;
import java.util.Collections;

public class B {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        int n = Integer.valueOf(cin.nextLine().replace(" ", ""));
        ArrayList<String> list = new ArrayList<>();
        while(n-->0){
            list.add(cin.nextLine().replace(" ", ""));
        }
        Collections.sort(list,new Comparator<String>() {

            @Override
            public int compare(String o1, String o2) {

                String s1 = o1.substring(6, 14);
                String s2 = o2.substring(6, 14);
                if(!s1.equals(s2)){
                    return s2.compareTo(s1);
                }
                return o1.compareTo(o2);
            }
        });

        for(String s:list){
            System.out.println(s);
        }

        cin.close();
    }


}
