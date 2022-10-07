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

const int maxn=1500+10;
int g[maxn][maxn];
int n,m;
struct node{
    int u,v,w;
};
vector<node> vec;

void sol(){
    cin>>n>>m;
    // memset(g,0x3f,sizeof g);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) g[i][j]=0;
            else g[i][j]=g[j][i]=inf;
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        vec.push_back((node){u,v,w});
        // g[u][v]=g[v][u]=min(g[u][v],w);
        g[u][v]=min(g[u][v],w);
    }    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }

    int mxd=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]==inf) continue;
            mxd=max(mxd,g[i][j]);
        }
    }

    for(auto x:vec){
        int u=x.u,v=x.v,w=x.w;
        
    }


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
