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

const int maxn=5e6+10;
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int dis[maxn];
bool st[maxn];
int n,m,c;
int S,T;

void dij(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    // memset(dis,0x7f,sizeof dis);
    // memset(st,0,sizeof st);
    for(int i=0;i<=n;i++) dis[i]=inf;
    dis[S]=0;
    pq.push({0,S});
    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int ver=t.second;
        if(st[ver]) continue;
        st[ver]=1;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[ver]+w[i]){
                dis[j]=dis[ver]+w[i];
                pq.push({dis[j],j});
            }
        }
    }
}

void sol(){
    cin>>n>>m>>c;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w);
        // cerr<<"add: "<<u<<' '<<v<<endl;
    }

    for(int i=0;i<=n;i++){
        for(int j=1;j<=n;j<<=1){
            if((i^j)>n) continue;
            add(i,i^j,j*c);
        }
    }
    cin>>S>>T;
    dij();
    cout<<dis[T]<<endl;
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
