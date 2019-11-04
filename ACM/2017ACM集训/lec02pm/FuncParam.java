package lec02pm;

import java.util.Date;

/**
 * Created by zj on 17-6-29.
 */
public class FuncParam {
    static int[] h( int n)
    {
        int a[]={1,2};
        return a;
    }
    static void swap(int[]a,int i,int  j)
    {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    static void swap(int a,int b)
    {
        int t=a;
        a=b;
        b=t;
    }
    static void foo(int x){//pass by Value
        x++;
    }
    static void foo(int g[])
    {
        g[0]++;
    }
    static void setDate(Date date)//pass by referrence
    {
        date.setYear(100);
    }
    public static void main(String[] args) {
        int x=3;
        foo(x);
        System.out.println(x);
        Date today=new Date();
        System.out.println(today);
        setDate(today);
        System.out.println(today);
    }
}
