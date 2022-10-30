#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 998244353
#define ll long long
#define int long long

using namespace std;

int n,m;
const int maxn=1e6+10;
int h[maxn],ne[maxn],e[maxn],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int f[maxn],d[maxn];
int siz[maxn];

void dfs(int u,int fa){
    siz[u]=1,d[u]=1;
    int cnt=0;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        siz[u]+=siz[j];
        d[u]=d[u]*d[j]%mod;
        if(siz[j]&1) cnt++;
    }
    if(cnt&1) cnt++;
    d[u]=d[u]*f[cnt]%mod;
}

void sol(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        add(u,v),add(u,v);
    }
    f[0]=1;
    for(int i=2;i<=n;i+=2){
        f[i]=f[i-2]*(i-1)%mod;
    }
    dfs(1,0);
    cout<<d[1]<<endl;

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
