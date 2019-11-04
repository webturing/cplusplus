package lec04;

/**
 * Created by Administrator on 2017/7/1 0001.
 */
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * 链表的使用
 */
public class P1582 {
    static Scanner cin = new Scanner(System.in);
    static PrintWriter cout = new PrintWriter(System.out);


    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<Integer>();
        for (int n = cin.nextInt(); n-- > 0; list.add(cin.nextInt())) ;
        while (list.size() > 1) {
            cout.print(list.pollFirst()+ " ");
            list.add(list.pollFirst());
        }
        cout.println(list.getFirst()+" ");
        cout.close();
        cin.close();
    }


}