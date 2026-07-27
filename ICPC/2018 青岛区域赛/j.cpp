#include<bits/stdc++.h>
#define int long long 
using namespace std ;
using pii = pair <int, int> ;
using pdi = pair <double, int> ;
const int N = 1e6 + 5 ;
const int inf = 1e18 ;
const int mod = 1e9 + 7 ;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    int cnt=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]==0) cnt++;
    }
    if(cnt>m){
        cout << "Impossible\n";
        return ;
    } 
    if(m == n){
        cout << "Richman\n";
        return ;
    }

   sort(a.begin() + 1, a.end());
   
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1; cin>>T;
    while(T--) 
        solve();
    return 0;
}