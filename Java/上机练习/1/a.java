import java.util.Scanner;

public class a
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long s = 0L;
        for(int i = 0; i < n; i ++)
        {
            int x = sc.nextInt();
            s += x;
        }
        System.out.println(s);
    }
}