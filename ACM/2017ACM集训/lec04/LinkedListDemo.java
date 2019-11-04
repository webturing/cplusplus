package lec04am;

import java.util.LinkedList;

/**
 * Created by zj on 17-7-1.
 */
public class LinkedListDemo {
    public static void main(String[] args) {
        Integer is[] = {6,3,1,7,5,8,9,2,4};
        LinkedList<Integer> list = new LinkedList<>();
        for (Integer i : is) {
            list.add(i);
        }
        // System.out.println(list.getFirst());
        //list.pollFirst();
        // System.out.println(list);

        //  Integer cur=list.pollFirst();
        //  list.addLast(cur);
        //System.out.println(list);
        while (true) {
            if (list.isEmpty())
                break;
            int cur = list.pollFirst();
            System.out.print(cur);
            if (list.isEmpty())
                break;
            list.addLast(list.pollFirst());
        }
    }
}
