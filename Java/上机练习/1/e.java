import java.util.Scanner;
import java.util.Arrays;

public class e
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        
        String s = sc.nextLine();
        if(s.equals(new StringBuilder(s).reverse().toString())) System.out.printf("yes\n");
        else System.out.printf("no");
    }
}
