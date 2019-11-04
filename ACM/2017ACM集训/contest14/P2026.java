package contest14;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Created by fan on 2017/7/16.
 */
public class P2026 {
    static int du[];
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n = cin.nextInt();
            if (n == 0) break;
            du = new int[n];
            Map<String, Integer> map= new HashMap<>();
            Boolean flag = true;
            for (int i = 0; i < n; i++) {
                String first = cin.next();
                String second = cin.next();
                if (first.equals(second)) {
                    flag = false;
                }
                if (flag) {
                    if (!map.containsKey(second)) {
                        map.put(second, 1);
                    } else
                        map.put(second, map.get(second) + 1);
                    if (!map.containsKey(first)) {
                        map.put(first, 0);
                    }
                }
            }
            int cnt = 0;
            for (String m : map.keySet()) {
                if (map.get(m) == 0) cnt++;
            }
            if (flag && cnt == 1)
                System.out.println("Yes");
            else
                System.out.println("No");
        }
        cin.close();
    }
}
