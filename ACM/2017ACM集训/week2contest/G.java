package week2contest;

import java.util.LinkedList;
import java.util.Scanner;


public class G {

    private static void solve(LinkedList<Step> l) {
        LinkedList<Step> rm = new LinkedList<>();
        LinkedList<Step> rh = new LinkedList<>();
        for (int i = 1; i < l.size(); i++) {
            Step c = l.get(i);
            Step p = l.get(i-1);
            if((c.a^c.b^c.c)==0||(p.a^p.b^p.c)==0){
                continue;
            }else{
                Step r = calculate(p);
                if(i%2==1) rm.add(r);
                else rh.add(r);
            }
        }
        if(rm.size()>0){
            System.out.println("XMing");
            for (Step s:rm) {
                System.out.println(s.a+" "+s.b+" "+s.c+"->"+s.ra+" "+s.rb+" "+s.rc);
            }
        }
        if(rh.size()>0){
            System.out.println("XHua");
            for (Step s:rh) {
                System.out.println(s.a+" "+s.b+" "+s.c+"->"+s.ra+" "+s.rb+" "+s.rc);
            }
        }
    }

    private static Step calculate(Step p) {
        int s = p.a^p.b^p.c;
        if(p.a>(p.a^s)) return new Step(p.a,p.b,p.c,p.a^s,p.b,p.c);
        if(p.b>(p.b^s)) return new Step(p.a,p.b,p.c,p.a,p.b^s,p.c);
        return new Step(p.a,p.b,p.c,p.a,p.b,p.c^s);
    }


    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        while (n-- > 0) {
            LinkedList<Step> list = new LinkedList<>();
            list.add(new Step(cin.nextInt(), cin.nextInt(), cin.nextInt()));
            int m = cin.nextInt();
            for (int i = 0; i < m; i++) {
                list.add(new Step(cin.nextInt(), cin.nextInt(), cin.nextInt()));
            }
            solve(list);
        }
        cin.close();
    }

    static class Step {
        int a, b, c;
        int ra, rb, rc;
        Step(int a1, int b1, int c1) {
            a = a1;b = b1;c = c1;
        }
        Step(int a1, int b1, int c1, int ra1, int rb1, int rc1) {
            a = a1;b = b1;c = c1;ra = ra1;rb = rb1;rc = rc1;
        }
    }
}
