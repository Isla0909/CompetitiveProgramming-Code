#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

std::vector<int> minp, primes;

void sieve(int n)
{
	minp.assign(n + 1, 0);
	primes.clear();

	for(int i = 2; i <= n; i ++)
	{
		if(!minp[i])
		{
			minp[i] = i;
			primes.push_back(i);
		}
		for(auto p : primes)
		{
			if(i * p > n) break;

			minp[i * p] = p;
			if(p == minp[i]) break;
		}
	}
}

void solve() {
	int n;
	std::cin >>n;

	std::cout <<n - 3 <<"\n";

}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	//sieve(1e5);

	int T;
	std::cin >>T;

	while(T --) {
		solve();
	}

	return 0;
}