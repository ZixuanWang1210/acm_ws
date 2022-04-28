#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int ans=1e55;
const int maxn=3e6+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int dp[maxn],cnt[maxn],c[maxn],f[maxn];
int tot;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int u,int fa){
    cnt[u]=c[u];

    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,u);
        cnt[u]+=cnt[j];
        f[u]=f[u]+f[j]+cnt[j]*w[i];
    }
}

// int dfs2(int u,int fa){
//     int res=0;

//     for(int i=h[u];~i;i=ne[i]){
//         int j=e[i];
//         if(j==fa) continue;
//         dfs2(j,u);
//         res+=w[i]*cnt[j];
//     }
//     return res;
// }

void dfs3(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dp[j]=1ll*dp[u]-w[i]*cnt[j]+(tot-cnt[j])*w[i];
        ans=min(ans,dp[j]);
        dfs3(j,u);
    }
}

signed main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        cin>>c[i];
        tot+=c[i];
    }
    for(int i=1;i<=n-1;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }

    dfs1(1,0);
    // int st=dfs2(1,-1);
    dp[1]=f[1];
    ans=min(ans,dp[1]);
    dfs3(1,0);
    // for(int i=1;i<=n;i++){
    //     ans=min(ans,dp[i]);
    // }
    cout<<ans<<endl;

    return 0;
}
