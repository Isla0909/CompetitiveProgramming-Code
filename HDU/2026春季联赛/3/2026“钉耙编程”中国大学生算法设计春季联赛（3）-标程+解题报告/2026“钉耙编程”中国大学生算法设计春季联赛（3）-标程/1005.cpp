#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,mod=998244353,M=37;
int T,n,q,a[N],p3[N];

inline int moonBit(int x,int t){
	return (x/p3[t])%3;
}

inline int moonXor(int x,int y){
	int z=0;
	for(int t=0;t<=M&&(x||y);t++)z+=p3[t]*((x+y)%3),x/=3,y/=3;
	return z;
}

int vis[N],num[N];

void ins(int x){
	for(int i=M;i>=0;i--)if(moonBit(x,i)){
		int v=moonBit(x,i);
		if(!vis[i]){
			vis[i]=1;
			if(v==2)x=moonXor(x,x);
			num[i]=x;
			return;
		}
		if(v==1)x=moonXor(x,x);
		x=moonXor(x,num[i]);
	}
	return;
}

bool query(int x){
	for(int i=M;i>=0;i--)if(moonBit(x,i)){
		if(!vis[i])return false;
		while(moonBit(x,i))x=moonXor(x,num[i]);
	}
	return !x;
}

int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}

signed main(){
//	freopen("sample.in","r",stdin);
//	freopen("sample.out","w",stdout);
	p3[0]=1;
	for(int i=1;i<=M;i++)p3[i]=p3[i-1]*3;
	T=read();
	int sumN=0,sumQ=0;
	while(T--){
		for(int i=0;i<=M;i++){
			vis[i]=num[i]=0;
		}
		n=read(),q=read();
		sumN+=n,sumQ+=q;
		for(int i=1;i<=n;i++){
			a[i]=read();
			ins(a[i]);
		}
		while(q--){
			if(query(read()))printf("Yes\n");
			else printf("No\n");
		}
	}
//	printf("sumN=%lld sumQ=%lld\n",sumN,sumQ);
    return 0;
}



