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

int n;
const int maxn=1e5+10;
ll dp[maxn][2];
int h[maxn],ne[maxn],e[maxn],idx;
pii w[maxn];
int p[maxn];

void add(int a,int b,pii c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

ll qPow(ll a, ll b){
    ll ans = 1, base = a;
    while(b > 0){
        if(b & 1) ans = ans*base%mod;
        base = base * base %mod, b >>= 1;
    }
    return ans;
}

void dfs(int u,int fa){
    dp[u][0]=1;

    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dp[u][0]*=(dp[j][1]*(w[i].second-w[i].first)*qPow(w[i].second,mod-2)+dp[j][0]);
        dp[u][1]=
    }
}

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        if(!x) p[i]=0;
        else p[i]=x*qPow(y,mod-2);
        dp[i][1]=p[i];
    }

    for(int i=1;i<=n-1;i++){
        int u,v,x,y; cin>>u>>v>>x>>y;
        pii ww={x,y};
        add(u,v,ww),add(v,u,ww);
    }

    dfs(1,-1);


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
