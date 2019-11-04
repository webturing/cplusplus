package lec07;



import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;


public class BinaryTree {

    private BinaryTree left;
    private String data;
    private BinaryTree right;

    private BinaryTree(String data) {
        this.data = data;
        left = right = null;
    }

    private static BinaryTree createBinaryTree(String[] list){
        Stack<BinaryTree> st = new Stack<>();
        BinaryTree b=null,p=null;
        int k=0;
        for (String s : list) {
            switch (s) {
                case "(":
                    st.push(p);k = 1;break;
                case ")":
                    st.pop();break;
                case ",":
                    k=2;break;
                default:
                    p = new BinaryTree(s);
                    if (b == null) b = p;
                    else {
                        if (k == 1) st.peek().left = p;
                        else st.peek().right = p;
                    }
                    break;
            }
        }
        return b;
    }

    private static void disp(BinaryTree b) {
        Queue<BinaryTree> qu = new LinkedList<>();
        qu.offer(b);
        while(qu.peek()!=null){
            BinaryTree cur = qu.poll();
            System.out.print(cur.data+" ");
            if(cur.left!=null)
                qu.offer(cur.left);
            if(cur.right!=null)
                qu.offer(cur.right);
        }
    }

    public static void main(String[] args) {
        String s = "9 ( 8 ( 5 , 6 ) , 7 ( 4 , 3 ) )";
        BinaryTree b = createBinaryTree(s.split("\\s+"));
        disp(b);
    }
}