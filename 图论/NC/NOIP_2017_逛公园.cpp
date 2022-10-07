#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=5e5+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool st[maxn];
int dis[maxn];
int f[maxn][51];
int n,m,k,p;
int mod;

void dij(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    dis[1]=0;
    pq.push({0,1});

    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int ver=t.second,d=t.first;
        if(st[ver]) continue;
        st[ver]=true;

        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>d+w[i]){
                dis[j]=d+w[i];
                pq.push({dis[j],j});
            }
        }
    }
}

struct seg{
    int u,v,w;
};
vector<seg> vec;
bool circle=0;
bool ok[maxn][51];

int dfs(int u,int d){
    if(circle) return 0;
    if(ok[u][d]){
        circle=true;
        return 0;
    }
    int& v=f[u][d];
    if(v) return v;
    ok[u][d]=true;
    int res=0;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        int t=dis[u]-dis[j]-w[i]+d;
        if(t<0||t>k) continue;
        (res+=dfs(j,t))%=mod;
    }
    ok[u][d]=false;
    return v=res;
}

void sol(){
    memset(h,-1,sizeof h); idx=0;
    memset(f,0,sizeof f);
    memset(ok,0,sizeof ok);
    circle=0;

    cin>>n>>m>>k>>mod;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        vec.push_back({u,v,w});
        add(u,v,w);
    }

    dij();

    memset(h,-1,sizeof h), idx=0;
    for(int i=0;i<m;i++){
        auto x=vec[i];
        add(x.v,x.u,x.w);
    }
    f[1][0]=1;
    int res=0;
    for(int i=0;i<=k;i++){
        (res+=dfs(n,i))%=mod;
    }
    if(circle) cout<<-1<<endl;
    else cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
