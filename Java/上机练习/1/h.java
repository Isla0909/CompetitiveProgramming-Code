import java.util.Scanner;
import java.util.Arrays;

public class Main
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i ++)
            a[i] = sc.nextInt();

        Arrays.sort(a);

        int x = sc.nextInt();
        int ans = 0;
        for(int i = 0; i < n; i ++)
            if(a[i] <= x + 30)
                ans ++;
        System.out.println(ans);
    }
}
