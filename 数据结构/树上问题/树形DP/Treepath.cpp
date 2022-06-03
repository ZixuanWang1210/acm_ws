#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

const int maxn=5e5+10;
vector<int> g[maxn];

int cnt0,cnt1;
int dep[maxn];

void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    if(dep[u]&1) cnt1++;
    else cnt0++;
    for(auto j:g[u]){
        if(j==fa) continue;
        dfs(j,u);
    }
}

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y),g[y].push_back(x);
    }

    dfs(1,-1);

    cout<<(cnt1*(cnt1-1)/2+cnt0*(cnt0-1)/2)<<endl;

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
