#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii array<long long,3>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=2e6+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int n,m;

ll dis[maxn][20];
bool st[maxn][20];
void dij(){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    memset(dis,0,sizeof dis);

    dis[1][0]=0,q.push({0,1,0});
    while(q.size()){
        auto [d,u,t]=q.top();
        
    }
}

void sol(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        add(u,v,0),add(v,u,1);
    }    
    for(int i=1;i<=n;i++){
        add(i,i+n,1);
    }

    int res=dij();

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
