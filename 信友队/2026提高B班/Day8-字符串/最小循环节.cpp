#include <bits/stdc++.h>
using namespace std;

vector<int> Z(string &s)
{
	int n = s.size();
	vector<int> z(n);
	z[0] = n;
	for(int i = 1, l = 0, r = 0; i < n; i ++)
	{
		if(i <= r) z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i] ++;
		if(i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;

	vector<int> z = Z(s);

	for(int p = 1; p < n; p ++)
	{
		if(n % p == 0 && z[p] == n - p)
		{
			cout << p << endl;
			return 0;
		}
	}

	cout << n << endl;

	return 0;
}