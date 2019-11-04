package contest01;

import java.util.Scanner;


/**
 * 完美代价
 * 贪心算法
 */
public class G {
    private static int count = 0; // 改变的次数
    private static int odd = 0; // 记录出现奇数次字符总数
    private static char oddChar = 0;// 记录奇数字符

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        String s = sc.nextLine();
        char str[] = s.toCharArray();
        if (!check(str)) {
            System.out.println("Impossible");
        } else {
            for (int i = 0; i < N / 2; i++) {
                if (str[i] != oddChar) {// 从右开始找对称
                    int j = 0;
                    for (j = N - 1 - i; j > i; j--) {
                        if (str[i] == str[j]) break;
                    }
                    count += N - 1 - i - j;
                    for (int k = j; k < N - 1 - i; k++) {
                        str[k] = str[k + 1];
                    }
                    str[N - 1 - i] = str[i];
                } else {// 从左边开始
                    int j = 0;
                    for (j = i; j < N - 1 - i; j++) {
                        if (str[j] == str[N - 1 - i]) break;
                    }
                    count += j - i;
                    for (int k = j; k > i; k--) {
                        str[k] = str[k - 1];
                    }
                    str[i] = str[N - 1 - i];
                }
            }
            System.out.println(count);
        }
    }


    private static boolean check(char[] str) {
        int freq[] = new int[26];
        for (char c : str) freq[c - 'a']++;

        for (int i = 0; i < freq.length; i++) {
            if (freq[i] % 2 == 1) {
                odd++;
                oddChar = (char) (i + 'a');
            }
        }
        if (odd > 1) return false;
        return true;
    }
}