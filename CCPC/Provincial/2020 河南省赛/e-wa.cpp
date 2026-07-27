#include<bits/stdc++.h>
using namespace std ;

#define int long long 
#define self this auto&&
using pii = pair <int, int> ;
using pdi = pair <double, int> ;
const int N = 2e4 + 5 ;
const int inf = 1e18 ;
const double eps = 1e-9;

struct node
{
    int a, b, w;
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<node> p(n);
    int idx = 0;
    
    vector<int> pos;
    for(int i = 0 ; i < n ; i ++ ) 
    {
        int a, b, w;
        cin >> a >> b >> w;
        p[i] = {a, b, w};
        pos.push_back(a - 1);
        pos.push_back(a);
        pos.push_back(a + 1);
        pos.push_back(b - 1);
        pos.push_back(b);
        pos.push_back(b + 1);
    }
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()),pos.end());

    auto find = [&](int x) -> int
    {
        return lower_bound(pos.begin(), pos.end(), x) - pos.begin() + 1;
    };

    int m = pos.size();
    vector<int> cnt(m + 1);
    vector<int> ans(m + 1);
    for(auto [a, b, w] : p)
    {
        a = find(a), b = find(b);
        //cout <<a <<" " <<b <<endl;
        cnt[a] ++ ;
        if(b + 1 <= m) cnt[b + 1] --;

        ans[a] ^= w;
        if(b + 1 <= m) ans[b + 1] ^= w;
    }
    int maxx = -1;
    for(int i = 1 ; i <= m ; i ++ )
    {
        cnt[i] += cnt[i - 1];
        ans[i] ^= ans[i - 1];
        //cout <<i <<" " <<cnt[i] <<" " <<ans[i] <<endl;
        if(cnt[i] >= k) maxx = max(maxx, ans[i]);
    }
    cout <<maxx << '\n';

}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);   
    int T=1; //cin>>T;
    while(T--) solve();
}