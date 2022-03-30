//dp[u][j]=>以u为根的子树中，保留大小为i的子树所需要删除的最小节点数
//dp[u][j]=min(dp[v][k]+dp[u][j-k])
//我切j个节点切的最少边数=min 我切j-k个节点的最少边数+我的儿子切k个节点的最少边数 

#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=3000;
int n,p;
int h[maxn],ne[maxn],e[maxn],idx;
int dp[maxn][maxn];
int c[maxn];

void add(int a,int b){
    e[idx]=b;ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    dp[u][1]=c[u];

    for(int i=h[u];~i;i=ne[i]){
        int v=e[i];
        if(v==fa) continue;
        dfs(v,u);
        for(int j=p;j>=1;j--){
            for(int k=1;k<j;k++){
                dp[u][j]=min(dp[u][j],dp[u][k]+dp[v][j-k]-2);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>p;
    memset(dp,0x3f,sizeof dp);
    
    memset(h,-1,sizeof h);
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        add(u,v),add(v,u);
        c[u]++,c[v]++;
    }

    dfs(1,-1);    
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++) ans=min(dp[i][p],ans);
    cout<<ans<<endl;

    return 0;
}
