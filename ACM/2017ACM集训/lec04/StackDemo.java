package lec04am;

import java.util.Stack;

/**
 * Created by zj on 17-7-1.
 */
public class StackDemo {
    public static void main(String[] args) {
        Stack<Character> stack = new Stack<>();
        String exp = "((b)a)()(";
        char cs[] = exp.toCharArray();
        boolean flag = true;
        for (char c : cs) {
            if (c == '(')
                stack.push(c);
            else if(c==')'){
                if (!stack.empty() && stack.peek() == '(') {
                    stack.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }
        System.out.println(flag&&stack.isEmpty());

    }
}
