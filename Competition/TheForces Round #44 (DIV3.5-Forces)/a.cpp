#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
	int n, x, y;
	std::cin >>n >>x >>y;
	std::cout <<((std::abs(x - y) - 1) % 2 ? "YES" : "NO") <<"\n";
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