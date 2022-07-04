#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=1100;
int h[maxn],e[maxn],ne[maxn],idx;
int n;
int dep[maxn],siz[maxn],cnt[maxn],_fa[maxn];
int d[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a];h[a]=idx++;
}

int cnt_z=0;
void dfs(int u,int fa){
    _fa[u]=fa;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        siz[u]++;
        // cout<<u<<endl;
        dfs(j,u);
    }
}

void dfs1(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        cnt_z+=(max(0ll,cnt[j]-1));
        dfs(j,u);
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
    for(int i=1;i<=n;i++){
        if(d[i]==1) cnt_z++;
    }
    dfs(1,0);
    bool bz=true;
    for(int i=1;i<=n;i++){
        if(d[i]==1&&_fa[i]==1&&bz){
            bz=false;
        }
        else if(d[i]==1&&_fa[i]==1&&!bz){
            cnt_z--;
        }
    }
    // cout<<cnt_z<<endl;
    dfs1(1,0);
    cout<<cnt_z<<endl;


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
