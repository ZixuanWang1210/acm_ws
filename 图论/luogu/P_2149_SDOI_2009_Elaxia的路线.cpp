#include<bits/stdc++.h>
#define y1 y11
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=20000;
int dis[maxn][maxn];
int n,m;
int x1,y1,x2,y2;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int h2[maxn],ne2[maxn],e2[maxn],w2[maxn],idx2;
int dp[maxn];
bool ok[maxn];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void add2(int a,int b,int c){
    e2[idx2]=b,w2[idx2]=c,ne2[idx2]=h2[a],h2[a]=idx2++,ok[a]=ok[b]=1;
}
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
}

int dfs(int u){
    if(dp[u]) return dp[u];
    for(int i=h2[u];~i;i=ne2[i]){
        int v=e2[i],wi=w2[i];
        dp[u]=max(dp[u],dfs(v)+wi);
    }
    return dp[u];
}

void sol(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    memset(h2,-1,sizeof h2);

    cin>>x1>>y1>>x2>>y2;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=inf;
        }
    }

    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w),add(v,u,w);
        dis[u][v]=dis[v][u]=min(dis[u][v],w);
    }

    floyd();
    // cout<<dis[1][3]<<' '<<dis[4][6]<<' '<<dis[1][6]<<endl;
    for(int i=1;i<=n;i++){
        // int i=1;
        for(int j=h[i];~j;j=ne[j]){
            int u=i,v=e[j],wi=w[j];
            // cout<<u<<' '<<v<<' '<<wi<<endl;
            if(dis[x1][u]+wi+dis[y1][v]==dis[x1][y1]){
                
                if(dis[x2][u]+wi+dis[v][y2]==dis[x2][y2]) add2(u,v,wi);
                if(dis[x2][v]+wi+dis[u][y2]==dis[x2][y2]) add2(u,v,wi);
            }
        }
    }

    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        if(ok[i]&&!dp[i]) dfs(i);
    }

    int res=-1;
    for(int i=1;i<=n;i++) res=max(res,dp[i]);
    cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
