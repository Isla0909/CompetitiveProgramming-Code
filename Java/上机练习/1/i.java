import java.util.Scanner;
import java.util.Arrays;

public class i
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] a = new int[n + 1];
        for(int i = 1; i <= n; i ++)
            a[i] = sc.nextInt();

        int k = sc.nextInt(), len = n;
        while(k != 0)
        {
            int x = sc.nextInt();
            for(int i = x + 1; i <= len; i ++)
                a[i - 1] = a[i];
            len --; k --;
        }
        for(int i = 1; i <= len; i ++)
        {
            System.out.printf("%d", a[i]);
            if(i != len) System.out.printf(" ");
        }
    }
}
