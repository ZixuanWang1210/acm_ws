#include<bits/stdc++.h>
using namespace std;

int n,ans;
const int maxn=1e5+10;
int dp[maxn];
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int dis[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u,int fa){
    int dist=0;
    int d1=0,d2=0;

    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        int d=dfs(j,u)+w[i];
        dist=max(dist,d);
        if(d>=d1) d2=d1,d1=d;
        else if(d>d2) d2=d;
    }
    ans=max(ans,d1+d2);
    return dist;
}

int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }

    dfs(1,-1);

    cout<<ans<<endl;

    return 0;
}