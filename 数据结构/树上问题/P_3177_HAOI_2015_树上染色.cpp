#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;

const int maxn=4000;
int w[maxn],h[maxn],ne[maxn],e[maxn],idx;
int siz[maxn];
int n,k;
int dp[maxn][maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    siz[u]=1;
    dp[u][0]=dp[u][1]=0;
    for(int i=h[u];~i;i=ne[i]){
        int v=e[i];
        if(v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
        for(int j=min(k,siz[u]);j>=0;j--){
            for(int kk=0;kk<=min(j,siz[v]);kk++){
                if(dp[u][j-kk]==-1) continue;
                int val=1ll*w[i]*kk*(k-kk)+1ll*w[i]*(siz[v]-kk)*(n-k-siz[v]+kk);
                dp[u][j]=max(dp[u][j],dp[u][j-kk]+dp[v][kk]+val);
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;

    memset(h,-1,sizeof h);
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w),add(v,u,w);
    }    

    dfs(1,-1);

    cout<<dp[1][k]<<endl;

    return 0;
}
