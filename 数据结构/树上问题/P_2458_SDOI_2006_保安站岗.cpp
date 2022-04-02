#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e6+10;
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
int n;
int dp[maxn][5];
int cost[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    dp[u][1]=cost[u];
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        dp[u][0]+=dp[j][1];
        dp[u][1]+=min(dp[j][0],dp[u][1]);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int ver,k,m; cin>>ver>>k>>m;
        cost[ver]=k;
        for(int i=1;i<=m;i++){
            int v; cin>>v;
            add(ver,v),add(v,ver);
        }
    }

    dfs(1,-1);
    int ans=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        ans=max(ans,min(dp[i][1],dp[i][0]));
    }
    cout<<ans<<endl;


    return 0;
}
