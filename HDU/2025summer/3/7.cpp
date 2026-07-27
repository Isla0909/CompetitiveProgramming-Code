#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::pair<int, u64>> a;
	for(int i = 0; i < n; i ++) {
		int l, r;
		std::cin >> l >> r;
		r ++;
		u64 x = rng();
		a.emplace_back(l, x);
		a.emplace_back(r, x);
	}
	std::sort(a.begin(), a.end());

	int lst = -1;
	u64 cur = 0;

	std::vector<i64> s{0};
	for(auto [i, x] : a) {
		if(i > lst) {
			s.push_back(cur);
		}
		lst = i;
		cur ^= x;
	}
	std::sort(s.begin(), s.end());
	int ans = std::unique(s.begin(), s.end()) - s.begin();
	std::cout << ans << "\n";
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