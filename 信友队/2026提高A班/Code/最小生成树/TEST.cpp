#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
};
edge g[200005];
int p[200055],c[100005];
int n,m;
vector<int> ng[100005];
int f[100005][25];
int dep[100005];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int find(int x){
    if(p[x]==x)return x;
	p[x]=find(p[x]);
    return p[x];
}
void join(int x,int y,int fath){
    int fx=find(x),fy=find(y);
    p[fx]=p[fy]=fath;
}
void dfs(int fa,int now,int depth){
	dep[now]=depth;
	f[now][0]=fa;
	for(int i=1;i<=19;i++){
		f[now][i]=f[f[now][i-1]][i-1];
	}
	for(auto i:ng[now]){
		if(i==fa)continue;
		dfs(now,i,depth+1);
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y); 
	for(int i=19;i>=0;i--){
		if(dep[f[y][i]]>=dep[x])y=f[y][i];
	}
	if(x==y)return x;
	for(int i=19;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[y][0];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	} 
	for(int i=1;i<=2*n;i++)p[i]=i; 
	sort(g+1,g+m+1,cmp);
	int idcnt=n;
	for(int i=1;i<=m;i++){
		int fu=find(g[i].u),fv=find(g[i].v);
		if(fu==fv)continue;
		idcnt++;
		c[idcnt]=g[i].w;
		ng[g[i].u].push_back(idcnt);
		ng[idcnt].push_back(g[i].u);
		ng[g[i].v].push_back(idcnt);
		ng[idcnt].push_back(g[i].v);
		join(g[i].u,g[i].v,idcnt);
	}
	dfs(0,idcnt,1);
	int q;
	cin>>q;
	while(q--){
		int at,bt;
		cin>>at>>bt;
		int lc=lca(at,bt);
		cout<<c[lc]<<'\n';
	}
    return 0;
}