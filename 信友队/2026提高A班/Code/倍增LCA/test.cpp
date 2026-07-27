#include<bits/stdc++.h>
#define int long long 
using namespace std;
int lg[100005],st[100005][20],year[100005],rain[100005];
void qlog(int x){
	lg[1]=0;
	for(int i=2;i<=x;i++){
		lg[i]=lg[i/2]+1;
	}
}
int qaf(int l,int r){
	if(l > r) return -1e9;
	int g=lg[r-l+1];
	return max(st[l][g],st[r-(1<<g)+1][g]);
}
signed main(){
	int n;
	cin>>n;
	qlog(n);
	for(int i=1;i<=n;i++)cin>>year[i]>>rain[i];
	for(int i=1;i<=n;i++){
		st[i][0]=rain[i];
	}
	for(int j=1;j<=lg[n];j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>y>>x;
		int py=lower_bound(year+1,year+n+1,y)-year;
		int px=lower_bound(year+1,year+n+1,x)-year;
		bool x_ext=0,y_ext=0;
		if(px<=n&&year[px]==x)x_ext=1;
		if(py<=n&&year[py]==y)y_ext=1;
        int lp=upper_bound(year+1,year+n+1,y)-year;
        int rp=px-1;
		int mxrain=qaf(lp,rp);
		if(x_ext==1&&y_ext==1){
			bool mid_ext=(px-py+1==year[px]-year[py]+1);
			if(mxrain>=rain[px] || rain[px] > rain[py])cout<<"false\n";
			else if(mid_ext==0)cout<<"maybe\n";
			else cout<<"true\n";
		}
		else if(x_ext==0&&y_ext==0)cout<<"maybe\n";
		else if(x_ext==1&&y_ext==0){
			if(mxrain>=rain[px])cout<<"false\n";
			else cout<<"maybe\n";
		}
		else if(x_ext==0&&y_ext==1){
			if(mxrain>=rain[py])cout<<"false\n";
			else cout<<"maybe\n";
		}
		
	}
	return 0;
}