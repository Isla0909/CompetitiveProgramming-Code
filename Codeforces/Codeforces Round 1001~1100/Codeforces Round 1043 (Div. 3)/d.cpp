#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

std::vector<i64> v(16); 

//从 1 写到 x 的总长度
i64 f(i64 x) {
	i64 res = 0;
	for(int i = 1; i <= 15; i ++) {
		if(x >= v[i]) {
			res += 1LL * v[i] * i;
			x -= v[i];
		} else {
			res += 1LL * i * x;
			break;
		}
	}
	return res;
}

i64 g(i64 x) {
	i64 res = 0;
	for(i64 c = 1; c <= x; c *= 10) {
		i64 high = x / (10 * c);
		int cur = x / c % 10;
		i64 low = x % c;
		res += 45LL * high * c + cur * (cur - 1) / 2 * c + cur * (low + 1);
	}
	return res;
}

void solve() {
	i64 k;
	std::cin >> k;

	i64 l = 0, r = k + 1;
	while(l + 1 != r) {
		i64 mid = l + r >> 1;
		if(f(mid) >= k) r = mid;
		else l = mid;
	}
	i64 ans = g(r);
	i64 m = f(r) - k;
	i64 x = r;
	for(int i = 0; i < m; i ++) {
		ans -= x % 10;
		x /= 10;
	}
	std:: cout <<ans <<"\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	v[1] = 9;
	for(int i = 2; i <= 15; i ++) {
		v[i] = 10 * v[i - 1];
	}

	int T;
	std::cin >> T;

	while(T --) {
		solve();
	}

	return 0;
}