import java.util.Scanner;

public class l
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[][] g = new int[n + 1][n + 1];
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                g[i][j] = sc.nextInt();

        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= n; j ++)
            {
                System.out.printf("%d", g[j][i]);
                if(j != n) System.out.printf(" ");
                else System.out.printf("\n");
            }
        }
    }
}