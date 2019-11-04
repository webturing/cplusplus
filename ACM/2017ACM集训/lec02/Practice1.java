/**
 * Created by zj on 17-6-29.
 */
public class Practice1 {
    public static void main(String[] args) {
        int x=1023;
        String s=Integer.toString(x);
        String s2=s.substring(1);//"023"
        int y=Integer.parseInt(s2);//23
        System.out.println(y);
        System.out.println(Integer.parseInt(Integer.toString(x).substring(1)));
    }
}
