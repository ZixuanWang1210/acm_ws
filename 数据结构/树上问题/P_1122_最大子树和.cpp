#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e4+10;
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
int n;
int dp[maxn];
int cost[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    dp[u]=cost[u];
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        dp[u]=max(dp[u],dp[u]+dp[j]);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    memset(h,-1,sizeof h);
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1,-1);

    // cout<<dp[1];
    int res=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        res=max(res,dp[i]);
        cout<<dp[i]<<' ';
    }
    cout<<res<<endl;

    return 0;
}
