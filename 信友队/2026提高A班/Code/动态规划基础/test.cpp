#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
const long long inf=-1e18;
int n,m;
long long f[N*50],sum;
struct node{
  int c,f,v,buy;
  bool operator<(const node&p)const{
    if(f!=p.f)return f>p.f;
    return buy<p.buy;
  }
}a[N<<1];
int main(){
  cin>>n;
  for(int i=1;i<=n;i++) 
    cin>>a[i].c>>a[i].f>>a[i].v,a[i].buy=0,sum+=a[i].c;
  cin>>m;
  for(int i=n+1;i<=n+m;i++) 
    cin>>a[i].c>>a[i].f>>a[i].v,a[i].buy=1;
  sort(a+1,a+1+n+m);

  // for(int i = 1; i <= n + m; i ++)
  //   cout <<a[i].c <<" " <<a[i].f <<" " <<a[i].v <<" " <<a[i].buy <<endl;

  fill(f,f+sum,inf);f[0]=0;
  for(int i=1;i<=n+m;i++)
  {
    cout <<a[i].c <<" " <<a[i].f <<" " <<a[i].v <<" " <<a[i].buy <<endl;
    if(a[i].buy == 0)
    {
      for(int j=sum;j>=a[i].c;j--)
      {
        if(f[j-a[i].c] == inf) continue;
        f[j]=max(f[j],f[j-a[i].c]-a[i].v);
      }
    }
    else
    {
      for(int j=0;j+a[i].c<=sum;j++)
      {
        if(f[j+a[i].c] == inf) continue;
        f[j]=max(f[j],f[j+a[i].c]+a[i].v);
      }
    }
    for(int j = 0; j <= sum; j ++)
      cout <<f[j] <<" \n"[j == sum];
  }
  cout<<*max_element(f+1,f+1+sum);
  return 0;
}