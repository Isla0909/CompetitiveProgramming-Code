import java.util.Scanner;

public class b
{   
    public static int max(int a, int b) {
        return a > b ? a : b;
    }

    public static void main(String[] args)
    {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = 0;
        for(int i = 0; i < n; i ++)
        {
            int x = sc.nextInt();
            s  = max(s, x);
        }
        System.out.println(s);
    }
}