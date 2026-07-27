import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			String s = sc.next();
			if(s.endsWith("n")) System.out.printf("%sg ", s);
			else System.out.printf("%s ", s);
		}
	}
}