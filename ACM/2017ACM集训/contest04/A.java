package contest04;

/**
 * Created by fjinh on 2017/7/3.
 */
public class A {
    public static void main(String[] args) {


        boolean[] a = new boolean[4];// 初始化默认都为false,假设都没偷
        boolean[] b = new boolean[4];
        // 假设偷的人为true
        for (int i = 0; i < 4; i++) {
            a[i] = true;
            if (i > 0) {
                a[i - 1] = false;
            }
            b[0] = !a[1] && a[3];
            b[1] = !a[1] && a[2];
            b[2] = !a[0] && a[1];
            b[3] = !a[3];
            if (b[0] != true) {
                if (!(a[1] == true && a[3] == false)) {
                    continue;
                }
            }
            if (b[1] != true) {
                if (!(a[1] == true && a[2] == false)) {
                    continue;
                }
            }
            if (b[2] != true) {
                if (!(a[0] == true && a[1] == false)) {
                    continue;
                }
            }
            System.out.println((char) (i + 65));
        }


    }
}