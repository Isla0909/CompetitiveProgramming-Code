import java.util.Scanner;
import java.util.Arrays;

public class f
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        
        while(true)
        {
            String choice = sc.nextLine();
            System.out.printf("choice=%s\n", choice);

            if(choice.equals("double"))
            {
                String line = sc.nextLine();
                String[] a = line.split("\\s+");

                double x1 = Double.parseDouble(a[0]);
                double x2 = Double.parseDouble(a[1]);
                double x3 = Double.parseDouble(a[2]);

                System.out.printf("%-5.2f,", x1);
                System.out.printf("%5.2f,", x2);
                System.out.printf("%.2f\n", x3);
            }
            else if(choice.equals("int"))
            {
                String line = sc.nextLine();
                String[] a = line.split("\\s+");

                int s = Integer.parseInt(a[0]) + Integer.parseInt(a[1]) + Integer.parseInt(a[2]);
                System.out.println(s);
            }
            else if(choice.equals("line"))
            {
                String s = sc.nextLine();
                System.out.println(s.toUpperCase());
            }
            else if(choice.equals("str"))
            {
                String s = sc.nextLine();
                String[] a = s.split("\\s+");

                System.out.println(a[2] + a[1] + a[0]);
            }
            else
            {
                System.out.println("other");
                break;
            }
        }
    }
}
