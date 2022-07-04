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

const int maxn=1100;
int h[maxn],e[maxn],ne[maxn],idx;
int n;
int dep[maxn],siz[maxn],cnt[maxn],_fa[maxn];
int d[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a];h[a]=idx++;
}

void init(int u,int fa){
    // siz[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dep[j]=dep[u]+1;
        init(j,u);
        siz[u]++;
    }
}

void dfs(int u,int fa){
    map<int,int> mp;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        mp[siz[j]]++;
        init(j,u);
    }
}

void sol(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int x,y; cin>>x>>y;
        add(x,y),add(y,x);
        d[x]++,d[y]++;
    }

    // dep[1]=1;
    init(1,-1);

    dfs(1,-1);
    
    int ans=0;
    for(int i=1;i<=n;i++){
        cout<<dep[i]<<' ';
    }
    for(int i=1;i<=n;i++){
        // if(d[i]==1) ans+=dep[i];
        // else ans-=(dep[i])*(siz[i]-1);
        if(siz[i]==0) ans+=dep[i];
        else ans=ans-(siz[i]-1)*dep[i];
    }
    cout<<ans<<endl;

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
