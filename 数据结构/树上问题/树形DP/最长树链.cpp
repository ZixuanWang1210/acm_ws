#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;


const int maxn=5e5+10;
int n,x,y,ans;
int a[maxn],f[maxn];
vector<int> g[maxn];

void dfs(int u,int len,int w){
    for(auto x:g[u]){
        int gcd=__gcd(a[x],w);
        if(gcd==1){
            ans=max(ans,len);
            dfs(x,1,a[x]);
        }
        else{
            ans=max(ans,len+1);
            dfs(x,len+1,gcd);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        int n; cin>>n;
        for(int i=0;i<n-1;i++){
            int x,y; cin>>x>>y;
            g[x].push_back(y);
            f[y]=1;
        }

        int root=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(!f[i]&&!root) root=i;
        }
        dfs(root,1,a[root]);
        cout<<ans<<endl;

    }


    return 0;
}
