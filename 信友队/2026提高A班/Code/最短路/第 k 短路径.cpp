#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
using namespace std;
struct edge{
    int u,v,w;
};
edge e[200005];
long long dist[1005][1005];
int ne[200005];
vector<int> kst;
int n,m,k,cnt=0;
bool cmp(edge a,edge b){
    return a.w<b.w;
}
void floyd(){
    for(int kk=1;kk<=cnt;kk++){
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=cnt;j++)
            dist[i][j]=min(dist[i][j],dist[i][kk]+dist[kk][j]);
        }
    }
}
int main(){
    memset(dist,0x3f,sizeof dist);
    
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e+1,e+m+1,cmp); 
    for(int i=1;i<=min(k, m);i++){
        if(ne[e[i].u]==0){
            cnt++;
            ne[e[i].u]=cnt;
        }
        if(ne[e[i].v]==0){
            cnt++;
            ne[e[i].v]=cnt;
        }
        dist[ne[e[i].u]][ne[e[i].v]]=e[i].w;
        dist[ne[e[i].v]][ne[e[i].u]]=e[i].w;
    }
    for(int i=1;i<=cnt;i++){
        dist[i][i]=0; 
    }
    floyd();
    for(int i=1;i<=cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            kst.push_back(dist[i][j]);
        }
    }
    sort(kst.begin(),kst.end());
    cout<<kst[k-1]; 
    return 0;
}