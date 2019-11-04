package lec02;

public class ArraysDemo2 {
    public static void main(String[] args) {
        int[] a={1,2,3};
        int [] b=new int[3];
        int [] c=a;//array c and a shared same memory
        c[0]++;
        System.out.println(a[0]);
        int[] d=new int[]{1,2,3};
        int [] e=a.clone();//
        int f[] =new int[a.length];
        for (int i = 0; i < a.length; i++) {
            f[i]=a[i];

        }


    }
}
