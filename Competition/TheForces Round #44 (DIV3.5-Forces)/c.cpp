#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;


void solve() {
	int n, l, r;
	std::cin >>n >>l >>r;

	if(n < l)
	{
		std::cout <<-1 <<"\n";
		return;
	}

	std::vector<int> div;
	for(int i = 1; i * i <= n; i ++) {
		if(n % i == 0) {
			div.push_back(i);
			if(i * i != n) div.push_back(n / i);
		}
	}
	std::sort(div.begin(), div.end());
	auto it = std::lower_bound(div.begin(), div.end(), l);

	if(it == div.end() || *it > r) {
		std::cout <<-1 <<"\n";
	} else {
		std::cout <<*it <<"\n";
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >>T;

	while(T --) {
		solve();
	}

	return 0;
}