import java.util.*;

public class c {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), T = sc.nextInt();
		long ans = 0;
		for(int i = 0; i < n; i ++)
		{
			long t = sc.nextInt(), k = sc.nextInt();
			if(ans + t <= T) ans += t;
			else
			{
				if(ans < T)
				{
					long delta = T - ans;
					ans = T;
					t -= delta;
				}
				else
				{
					ans ++; t --;
				}
				long c = ans - T;
				if(k - c + 1 > 0) ans += Math.min(t, k - c + 1);
			}
			//System.out.printf("%d %d\n", i, ans);
		}
		System.out.println(ans);
	}
}