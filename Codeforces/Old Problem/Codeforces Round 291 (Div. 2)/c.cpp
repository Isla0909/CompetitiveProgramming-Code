#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int P = 131;

pair<int, int> getHash(const string &s)
{
	i64 h1 = 0, h2 = 0;
	i64 p1 = 1, p2 = 1;

	for(char c : s)
	{
		int x = c - 'a' + 1;

		h1 = (h1 + x * p1) % mod1;
		h2 = (h2 + x * p2) % mod2;

		p1 = p1 * P % mod1;
		p2 = p2 * P % mod2;
	}
	return {(int)h1, (int)h2};
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> a(n), q(m);

	int mx = 0;

	for(auto &s : a)
	{
		cin >> s;
		mx = max(mx, (int)s.size());
	}

	for(auto &s : q)
	{
		cin >> s;
		mx = max(mx, (int)s.size());
	}

	vector<i64> p1(mx + 1), p2(mx + 1);

	p1[0] = p2[0] = 1;

	for(int i = 1; i <= mx; i++)
	{
		p1[i] = p1[i - 1] * P % mod1;
		p2[i] = p2[i - 1] * P % mod2;
	}

	vector<array<int, 3>> st;

	for(auto &s : a)
	{
		auto [h1, h2] = getHash(s);
		st.push_back({(int)s.size(), h1, h2});
	}

	sort(st.begin(), st.end());

	for(auto &s : q)
	{
		auto [h1, h2] = getHash(s);

		bool f = false;

		for(int i = 0; i < s.size() && !f; i++)
		{
			int x = s[i] - 'a' + 1;

			for(int y = 1; y <= 3; y++)
			{
				if(x == y)
					continue;

				int nh1 = (h1 - x * p1[i] % mod1 + mod1) % mod1;
				nh1 = (nh1 + y * p1[i]) % mod1;

				int nh2 = (h2 - x * p2[i] % mod2 + mod2) % mod2;
				nh2 = (nh2 + y * p2[i]) % mod2;

				if(binary_search(st.begin(), st.end(),
					array<int, 3>{(int)s.size(), nh1, nh2}))
				{
					f = true;
					break;
				}
			}
		}

		cout << (f ? "YES" : "NO") << '\n';
	}
}