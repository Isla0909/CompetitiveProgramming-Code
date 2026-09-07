#include <iostream>
#define endl '\n'
using namespace std;

signed main()
{
	int T = 0;
	while(true)
	{
		cout <<"test: " <<++T <<endl;

		system("data.exe > data.in");
		system("AC.exe < data.in > AC.out");
		system("WA.exe < data.in > WA.out");

		if(system("fc AC.out WA.out > diff.out"))
		{
			cout << "\n\n";
			cout << "==================== Wrong Answer ====================\n\n";

			cout << "===================== data.in =====================\n";
			system("type data.in");

			cout << "\n\n===================== AC.out ======================\n";
			system("type AC.out");

			cout << "\n\n===================== WA.out ======================\n";
			system("type WA.out");

			cout << "\n\n===================================================\n";

			break;
		}
		cout <<"Accepted" <<endl;
	}
	return 0;
}