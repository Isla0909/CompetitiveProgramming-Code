#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

const int N = 5e5 + 10, P = 131;

u64 h1[N], h2[N], p[N];

u64 fun1(int l, int r)
{
	return h1[r] - h1[l - 1] * p[r - l + 1];
}

u64 fun2(int l, int r)
{
	return h2[r] - h2[l - 1] * p[r - l + 1];
}

int n;
bool check(int l, int r)
{
	return fun1(l, r) == fun2(n + 1 - r, n + 1 - l);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >>s;
	n = s.size();
	string s1 = " " + s;
	reverse(s.begin(), s.end());
	string s2 = " " + s;

	vector<vector<i64>> pre(n + 1, vector<i64>(26, 0));
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j < 26; j ++)
			pre[i][j] = pre[i - 1][j] + (s1[i] - 'a' == j); 

	//cout <<s1 <<endl <<s2 <<endl;
	p[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		h1[i] = h1[i - 1] * P + s1[i] - 'a' + 1;
		h2[i] = h2[i - 1] * P + s2[i] - 'a' + 1;
		p[i] = p[i - 1] * P;
	}

	unordered_map<u64, bool> mp1;
	unordered_map<u64, bool> mp2;
	vector<i64> cnt(26);
	for(int i = 1; i <= n; i ++)
	{
		int less = min(i - 1, n - i);
		int l = -1, r = less + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(check(i - mid, i + mid)) l = mid;
			else r = mid;
		}
		int L = i - l, R = i + l;
		// cout <<i <<" " <<s1[i] <<" " <<L <<" " <<R <<endl;
		while(L <= R)
		{
			u64 val = fun1(L, R);
			if(mp1[val]) break;

			mp1[val] = true;
			
			for(int j = 0; j < 26; j ++)
				cnt[j] += pre[R][j] - pre[L - 1][j];

			L ++, R --;
		}
	}

	for(int i = 1; i + 1 <= n; i ++)
	{
		if(s1[i] != s1[i + 1]) continue;

		int less = min(i - 1, n - (i + 1));
		int l = -1, r = less + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(check(i - mid, i + 1 + mid)) l = mid;
			else r = mid;
		}
		int L = i - l, R = i + 1 + l;
		// cout <<i <<" " <<L <<" " <<R <<endl;
		while(L <= R)
		{
			u64 val = fun1(L, R);
			if(mp2[val]) break;

			mp2[val] = true;
			
			for(int j = 0; j < 26; j ++)
				cnt[j] += pre[R][j] - pre[L - 1][j];

			L ++, R --;
		}
	}

	vector<int> p(26);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int i, int j)
	{
		if(cnt[i] != cnt[j]) return cnt[i] < cnt[j];
		return i < j;
	});
	int ans = 0;
	for(int i = 0; i < 26; i ++)
		if(cnt[i]) ans ++;
	cout <<ans <<endl;
	for(int i = 0; i < 26; i ++)
		if(cnt[p[i]]) cout <<char('a' + p[i]) <<" ";
	return 0;
}