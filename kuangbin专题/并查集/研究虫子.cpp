#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=5e3+10;
int p[maxn];
int dis[maxn];
int n,m;

int find(int x){
    if(x==p[x]) return x;
    int root=find(p[x]);
    dis[x]+=dis[p[x]];
    dis[x]%=2;
    // dis[x]^=dis[p[x]];
    return p[x]=root;
}

bool merge(int x,int y){
    int px=find(x),py=find(y);
    if(px==py){
        if((dis[x]+dis[y])%2==0) return false;
        else return true;
    }
    p[py]=px;
    // dis[py]=dis[y]^1^dis[x];
    dis[py]=dis[x]-dis[y]+1;
    dis[py]%=2;
    return true;
}

// void init(){
//     memset(p,0,sizeof p);
//     memset(dis,0,sizeof dis);
// }

void sol(){
    // init();
    cin>>n>>m;
    for(int i=0;i<=n;i++) p[i]=i,dis[i]=0;
    int ok=false;

    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b; 
        if(merge(a,b)==false) ok=true;
    }
    if(ok) cout<<"Suspicious bugs found!"<<endl;
    else cout<<"No suspicious bugs found!"<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    for(int i=1;i<=_;i++){
        cout<<"Scenario #"<<i<<":"<<endl;
        sol();
        cout<<endl;
    }

    return 0;
}
