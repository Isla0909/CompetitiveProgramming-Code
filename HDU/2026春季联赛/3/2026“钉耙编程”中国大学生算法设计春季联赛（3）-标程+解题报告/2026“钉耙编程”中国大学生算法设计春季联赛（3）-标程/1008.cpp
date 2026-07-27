#include <bits/stdc++.h>
using namespace std;

const int N=1.02e7,mod=998244353;
const int p4[4]={1,4,16,64};
const int S[40]={21,22,23,25,29,53,54,57,61,63,
			69,70,71,73,77,81,83,84,92,97,
			100,108,113,116,124,145,147,148,156,197,
			198,199,201,205,207,209,211,212,220,252};
unsigned long long f[2][40];
int to[40][2],mp[256];
char C;

const int MB=1<<20;
struct FastIO{
    char ib[MB+100],*p,*q;
    char ob[MB+100],*r,stk[128];
    int tp;
    FastIO(){p=q=ib,r=ob,tp=0;}
    ~FastIO(){fwrite(ob,1,r-ob,stdout);}
    char read_char(){
        if(p==q){
            p=ib,q=ib+fread(ib,1,MB,stdin);
            if(p==q)return 0;
        }
        return *p++;
    }
    template<typename T>
    void read_int(T& x){
        char c=read_char(),l=0;
        for(x=0;!isdigit(c);c=read_char())l=c;
        for(;isdigit(c);c=read_char())x=x*10-'0'+c;
        if(l=='-')x=-x;
    }
    
    void write_char(char c){
        if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
        *r++=c;
    }
    template<typename T>
    void write_int(T x){
        if(x<0)write_char('-'),x=-x;
        do stk[++tp]=x%10+'0';
        while(x/=10);
        while(tp)write_char(stk[tp--]);
    }
}IO;

void solve(){
	while(C!='0'&&C!='1')C=IO.read_char();
	int T=0,j=0,n=0;
	long long ans=0;
	for(int i=0;i<40;i++)f[0][i]=f[1][i]=0;
	f[T][39]=1;
	while(C=='0'||C=='1'){
		copy(&f[T][0],&f[T][0]+40,&f[T^1][0]);
		T^=1,C-=48,++n;
		for(j=0;j<40;j++){
			f[T][to[j][C]]+=f[T^1][j];
		}
		if((n&15)==0){
			for(int j=0;j<40;j++)f[T][j]%=mod;
		}
		C=IO.read_char();
	}
	for(int j=0;j<40;j++){
		int mn=4,_j=S[j];
		for(int z=0;z<4;z++){
			int p=_j%4;
			_j/=4;
			if(z&1)mn=min(mn,p+1);
		}
		(ans+=1ll*(mn%4)*f[T][j]%mod)%=mod; 
	}
	IO.write_int(ans);
	IO.write_char(10);
	return;
}

signed main(){
	for(int j=0;j<40;j++)mp[S[j]]=j;
	for(int j=0;j<40;j++){
		for(int c=0;c<=1;c++){
			int t[4]={3,3,3,3},_j=S[j];
			for(int z=0;z<4;z++){
				int p=_j%4;
				_j/=4;
				if(p==3)continue;
				int _x=(z&1),_y=((z>>1)&1);
				if(!c)_x^=_y;
				else _y^=1;
				int _z=_x+_y*2;
				t[_z]=min(t[_z],p);
				if(p<2&&(z&1)){
					if(!c)t[0]=min(t[0],p+1);
					else t[2]=min(t[2],p+1);
				}
			}
			to[j][c]=mp[t[0]*1+t[1]*4+t[2]*16+t[3]*64];
		}
	}
	
	int T=1;
	IO.read_int(T);
	while(T--)solve();
    return 0;
}



