#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

const int maxn=1e5+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int siz[maxn];
int ans;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    siz[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        siz[u]+=siz[j];
        if(siz[j]&1) ans+=w[i];
    }
}

void sol(){
    int n; cin>>n;

    for(int i=0;i<2*n;i++){
        w[i]=h[i]=siz[i]=e[i]=0;
        h[i]=-1;
    }
    ans=0,idx=0;

    for(int i=1;i<=n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w),add(v,u,w);
    }

    dfs(1,-1);

    cout<<ans<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
