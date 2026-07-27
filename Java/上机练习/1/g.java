import java.util.Scanner;
import java.util.Arrays;

public class g
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i ++)
            a[i] = sc.nextInt();

        for(int i = 0, j = n - 1; i < j; i ++, j --)
            System.out.printf("%d %d\n", a[i], a[j]);
    }
}
