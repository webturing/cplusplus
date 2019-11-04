package contest03;

/**
 * Created by fan on 17-7-1.
 */
import java.util.Scanner;



public class F {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {

            int m = cin.nextInt();
            int n = cin.nextInt();
            int tot = cin.nextInt();
            int[][] a = new int[m + 2][n + 2];
            for (int i = 0; i < m + 2; i++) {
                for (int j = 0; j < n + 2; j++) {
                    a[i][j] = 0;
                }
            }
            for (int i = 0; i < tot; i++) {

                int x = cin.nextInt();
                int y = cin.nextInt();
                a[x + 1][y + 1] = -1;
            }
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if(a[i][j]!=-1){
                        if(a[i-1][j-1]==-1)
                            a[i][j]++;
                        if(a[i-1][j]==-1)
                            a[i][j]++;
                        if(a[i-1][j+1]==-1)
                            a[i][j]++;
                        if(a[i][j-1]==-1)
                            a[i][j]++;
                        if(a[i][j+1]==-1)
                            a[i][j]++;
                        if(a[i+1][j-1]==-1)
                            a[i][j]++;
                        if(a[i+1][j]==-1)
                            a[i][j]++;
                        if(a[i+1][j+1]==-1)
                            a[i][j]++;
                    }
                }
            }
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if(a[i][j]==-1)
                        System.out.print("*");
                    else{
                        System.out.print(a[i][j]);
                    }
                }
                System.out.println();
            }
            System.out.println();

        }

        cin.close();

    }

}

