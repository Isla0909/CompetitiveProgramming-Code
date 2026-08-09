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

int calc(string s)
{
	int n = s.size();
	string r = s;
	reverse(r.begin(), r.end());

	string t = r + "#" + s;
	vector<int> z = Z(t);

	int ans = 0;
	for(int k = 0; k < n; k ++)
	{
		int len = z[n + 1 + k];
		len = min(len, (n - k) / 2);
		ans = max(ans, len);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int n = s.size();
	int c = 0;

	while(c < n / 2 && s[c] == s[n - 1 - c])
		c ++;

	if(c == n / 2)
	{
		cout << c << endl;
		return 0;
	}

	string mid = s.substr(c, n - 2 * c);

	int ans = calc(mid);

	reverse(mid.begin(), mid.end());
	ans = max(ans, calc(mid));

	cout << c + ans << endl;

	return 0;
}