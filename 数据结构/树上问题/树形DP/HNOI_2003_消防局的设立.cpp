#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

const int maxn=1e3+10;
vector<int> g[maxn];
int n;
int ans,res;

// void dfs(int u,int fa,int dep){
//     // cout<<u<<' '<<dep<<endl;
//     // if(dep==0) {
//     //     res++;
//     //     dep=3;
//     // }
//     for(auto j:g[u]){
//         if(j==fa) continue;
//         if(dep-1==0){
//             res++;
//             dep=2;
//         }
//         dfs(j,u,dep-1);
//     }
// }
bool st[maxn]={true};
int dep[maxn],fa[maxn];
void dfs(int u,int d){
    st[u]=false;
    if(d==0) return;
    for(auto j:g[u]){
        dfs(j,d-1);
    }
    dfs(fa[u],d-1);
}

void sol(){
    cin>>n;
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        g[x].push_back(i);
        // g[i].push_back(x);
        fa[i]=x;
    }
    fa[1]=1;

    for(int i=1;i<=n;i++) dep[i]=dep[fa[i]]+1;
    memset(st,1,sizeof st);

    while(1){
        int t=0;
        for(int i=1;i<=n;i++){
            if(st[i]&&dep[i]>dep[t]) t=i;
        }
        if(t==0) break;
        dfs(fa[fa[t]],2);
        ans++;
    }

    // for(int i=1;i<=n;i++){
    //     res=1;
    //     dfs(i,-1,2);
    //     ans=min(ans,res);
    // }
    // res=1;
    // dfs(3,-1,3);
    cout<<ans<<endl;

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
