#include <bits/stdc++.h>
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

const int maxn=5e5+10;
int h[maxn],ne[maxn],e[maxn],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int n,m;
int dp[maxn][3];

void dfs(int u){
    if(h[u]==-1) dp[u][0]=dp[u][1]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        dfs(j);
        dp[u][1]=max(dp[u][1],dp[j][1]+1);
        dp[u][0]+=dp[j][0];
    }
    dp[u][0]=max(dp[u][0],dp[u][1]);
}

void sol(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        add(x,i);
    }
    dfs(1);
    cout<<dp[1][0]<<endl;
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
