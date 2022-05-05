// 类似没有上司的舞会
// 最大独立集问题
#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=1e6+10;
int h[maxn],ne[maxn],e[maxn],idx;
int dp[maxn][3];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){

    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        dp[u][1]+=dp[j][0];
        dp[u][0]+=max({dp[j][1],dp[j][0]});
    }
    dp[u][1]++;
}

void sol(){
    int n; cin>>n;
    int root; cin>>root;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int a,b; cin>>a>>b; 
        add(a,b),add(b,a);
    }

    dfs(root,-1);
    cout<<dp[root][1]<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
