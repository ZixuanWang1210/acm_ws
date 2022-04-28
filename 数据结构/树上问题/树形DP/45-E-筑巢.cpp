#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=1e6+10;
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
int cost[maxn];
int dis[maxn];
int ans=-0x3f3f3f3f;
int n;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u,int fa){
    // int d1=0,d2=0;
    dis[u]=cost[u];

    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        int dist=dfs(j,u)+w[i];
        // if(dist>d1) d2=d1,d1=dist>0?dist:0;
        // else if(dist>d2) d2=dist>0?dis[u]:0;
        if(dist>0) dis[u]+=dist;
        // cout<<u<<' '<<d1<<' '<<d2<<endl;
    }
    ans=max(ans,dis[u]);
    return dis[u];
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
        ans=max(ans,cost[i]);
    }
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    dfs(1,-1);
    // int ans=0;
    // for(int i=1;i<=n;i++){
    //     ans=max(ans,dis[i]);
    // }
    cout<<ans;

    return 0;
}