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

const int maxn=1e6+10;
int dis[maxn];
bool st[maxn];
int h[maxn],ne[maxn],e[maxn],w[maxn];
int idx;

void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
int n,m,s,t;

void dij(){
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});

    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int ver=t.second,dist=t.first;
        if(st[ver]) continue;
        st[ver]=1;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(st[j]) continue;
            if(dis[j]>dis[ver]+w[i]){
                dis[j]=dis[ver]+w[i];
                pq.push({dis[j],j});
            }
        }
    }
}

void sol(){
    cin>>n>>m>>s>>t;
    memset(h,-1,sizeof h);

    for(int i=1;i<=m;i++){
        int op,a,b,c; cin>>op>>a>>b>>c;
        if(op) add(a,b,c),add(b,a,c);
    }

    dij();

    if(dis[t]==inf) cout<<"My gold!!!"<<endl;
    else cout<<dis[t]<<endl;
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
