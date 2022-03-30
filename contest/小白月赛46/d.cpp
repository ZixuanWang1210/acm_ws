#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
#define pii pair<int,int>

// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=2e2+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int n,k;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

// int ans=1;
// int dfs(int u,int fa,int dis){
//     for(int i=h[u];~i;i=ne[i]){
//         int j=e[i];
//         if(j==fa) continue;
//         int tt=dis+w[i];
//         if(dis+w[i]<=2){
//             ans++;
//             dfs(j,u,w[i]+dis);
//         }
//     }
//     return ans;
// }
int dp[1010][3];
int cnt[maxn];
void dfs(int u,int fa){
    
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        if(w[i]==1) cnt[u]++,dp[u][1]++,cnt[u]+=dp[j][1];
        if(w[i]==2) cnt[u]++;
    }
    cnt[u]+=dp[u][1]+1;
}
void dfs1(int u,int fa){
    cnt[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,u);
        if(w[i]==1) dp[u][1]++,cnt[u]++,cnt[u]+=dp[j][1];
        if(w[i]==2) cnt[u]++;
    }
}
signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=2;i<=n;i++){
        int fa,d; cin>>fa>>d;
        add(fa,i,d),add(i,fa,d);
        // if(d==1) dp[i][1]=1;
        // if(d==2) dp[i][2]=1;
    }
    // memset(cnt,1,sizeof cnt);
    dfs1(1,-1);
    for(int i=1;i<=n;i++){
        // ans=1;
        // cout<<dfs(i,-1,0)<<endl;
        cout<<cnt[i]<<endl;
    }

    return 0;
}
