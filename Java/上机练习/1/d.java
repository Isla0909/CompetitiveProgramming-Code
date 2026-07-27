import java.util.Scanner;
import java.util.Arrays;

public class d
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        double[] f = new double[n];
        for(int i = 0; i < n; i ++)
            f[i] = sc.nextDouble();
        
        Arrays.sort(f);

        double s = 0.0;
        for(int i = 1; i < n - 1; i ++)
            s += f[i];

        System.out.printf("%.2f\n", s / (n - 2));
    }
}
