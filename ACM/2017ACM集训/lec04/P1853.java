package lec04am;

import java.util.Stack;

/**
 * Created by zj on 17-7-1.
 */
public class P1853 {
    public static void main(String[] args) {
        Stack<Character> stack=new Stack<>();
        for(int i=0;i<5;i++)
            stack.push((char)('a'+i));
        System.out.println(stack);
        stack.pop();
        System.out.println(stack);
        stack.push('x');
        System.out.println(stack.peek());
        stack.pop();
        stack.pop();
        System.out.println(stack);

    }
}
