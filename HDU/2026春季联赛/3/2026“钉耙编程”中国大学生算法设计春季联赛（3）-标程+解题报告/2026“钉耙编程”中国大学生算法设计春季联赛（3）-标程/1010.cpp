#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N=5.01e3,mod=998244353;
int T,C[N][N],n,a[N]; 

signed main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	cin>>T;
	C[0][0]=1;
	for(int i=1;i<N;i++){
		C[i][0]=1;
		for(int j=1;j<N;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod; 
	}
	while(T--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			int d=min(a[1],a[i]-a[i-1]);
			(ans+=C[a[i]][d])%=mod;
		}
		printf("%d\n",ans);
	}
    return 0;
}



