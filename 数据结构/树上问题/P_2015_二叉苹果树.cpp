#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1e4+10;
int dp[maxn][maxn];
int n,q;
int e[maxn*2],ne[maxn*2],h[maxn*2],w[maxn*2],idx;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int ver=e[i];
        if(ver==fa) continue;;
        dfs(ver,u);
        for(int j=q;j>=1;j--){
            // for(int k=j-1;k>=0;k--){
            for(int k=0;k<=j-1;k++){
                dp[u][j]=max(dp[u][j],dp[u][j-k-1]+dp[ver][k]+w[i]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w),add(v,u,w);
    }

    dfs(1,-1);
    
    cout<<dp[1][q];
    return 0;
}
