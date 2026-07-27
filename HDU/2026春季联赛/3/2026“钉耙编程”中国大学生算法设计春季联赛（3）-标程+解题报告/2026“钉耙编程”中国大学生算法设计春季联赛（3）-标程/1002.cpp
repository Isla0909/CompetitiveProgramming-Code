#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N=1.01e6,mod=998244353;
int ans[N],T,n;

signed main(){
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	ans[1]=1;
	ans[2]=2;
	ans[3]=4;
	ans[4]=6;
	ans[5]=9;
	ans[6]=13;
	ans[7]=17;
	for(int i=8;i<N;i++)ans[i]=(ans[i-4]*2+10)%mod;
	cin>>T;
	while(T--){
		cin>>n;
		printf("%d\n",ans[n]);
	}
    return 0;
}



