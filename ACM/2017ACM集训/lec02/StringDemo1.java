package lec02;
import java.util.Arrays;

/**
 * Created by zj on 17-6-29.
 */
public class StringDemo1 {
    public static void main(String[] args) {
        String a="abc"+"def";
        a=a+"qdef";//a="abcdefqdef"
        System.out.println(a);
        System.out.println(a.length());//7
        System.out.println(a.charAt(3));//'d'
        System.out.println(a.indexOf('x'));//'x' not in a
        System.out.println(a.indexOf('q'));//'q'  in a ,index of'q' is 6
        System.out.println(a.indexOf("def"));//3
        System.out.println(a.lastIndexOf("def"));
        String b="abcdefqdef";
        System.out.println(b==a);// a==b  compare value if a is primetive datatype,otherwise compare a,b is same object
        System.out.println(b.equals(a));//true
        System.out.println(b.equalsIgnoreCase(a));
        System.out.println(b.toUpperCase());
        System.out.println(b.toLowerCase());
        System.out.println(b.trim());
        char cs[]="abcdef".toCharArray();
        String[] words="I love you".split(" ");
        System.out.println(Arrays.toString(words));
        System.out.println("we think we can".replaceAll("we","you"));
        String text="asbcdsfa123$%%^&^&*894ajsfdjk123";
        String numbers[]=text.split("\\s*\\D+\\s*");
        System.out.println(Arrays.toString(numbers));
        String exp="1+2-3*4 / 5";
        System.out.println(Arrays.toString(exp.split("\\D+")));
        System.out.println(Arrays.toString("192.168.0.1".split("\\.")));
    }
}
