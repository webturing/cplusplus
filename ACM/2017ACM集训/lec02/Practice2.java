/**
 * Created by zj on 17-6-29.
 */
public class Practice2 {
    public static void main(String[] args) {
        String tel="13625500036";
        //"136****0036";
        System.out.print(tel.substring(0,3));
        System.out.print("****");
        System.out.println(tel.substring(tel.length()-4));
        System.out.println("hello"+"world");
        System.out.println("1"+2);//1+Integer.toString(2)
        System.out.println(1+"2");
        System.out.println(1+'2');
        System.out.println('1'+'2');
        System.out.println(""+'1'+'2');
    }
}
