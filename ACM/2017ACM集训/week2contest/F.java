package week2contest;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class F {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        while (cin.hasNextLine()) {
            ArrayList<String> list = new ArrayList<>();
            String[] data = cin.nextLine().trim().split("\\s+");
            list.addAll(Arrays.asList(data));
            double ans = Double.valueOf(solve(list));
            System.out.printf("%.2f\n",Math.abs(ans));
        }
        cin.close();
    }

    private static String solve(List<String> l) {

        for (int i = 0; i < l.size(); i++) {
            if ("*/".contains(l.get(i))) {
                String ans = calculate(l.get(i - 1), l.get(i), l.get(i + 1));
                l.remove(i - 1);
                l.remove(i - 1);
                l.remove(i - 1);
                l.add(i - 1, ans);
                i--;
            }
        }
        for (int i = 0; i < l.size(); i++) {
            if ("+-".contains(l.get(i))) {
                String ans = calculate(l.get(i - 1), l.get(i), l.get(i + 1));
                l.remove(i - 1);
                l.remove(i - 1);
                l.remove(i - 1);
                l.add(i - 1, ans);
                i--;
            }
        }
        return l.get(0);
    }

    private static String calculate(String a, String op, String b) {
        switch (op) {
            case "+":
                return String.valueOf(Double.valueOf(a) + Double.valueOf(b));
            case "-":
                return String.valueOf(Double.valueOf(a) - Double.valueOf(b));
            case "*":
                return String.valueOf(Double.valueOf(a) * Double.valueOf(b));
            default:
                return String.valueOf(Double.valueOf(a) / Double.valueOf(b));
        }
    }
}
