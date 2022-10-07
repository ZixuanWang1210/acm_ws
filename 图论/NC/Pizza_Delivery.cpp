#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x7f7f7f7f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=5e2+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int n,m;

int dis[4][maxn];
bool st[4][maxn];
void dij(int s){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=1;i<=n;i++){
        dis[s][i]=inf;
    }
    dis[s][s]=0;
    pq.push({0,s});

    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int d=t.first,ver=t.second;
        if(st[s][ver]) continue;
        st[s][ver]=true;

        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dis[s][j]>d+w[i]){
                dis[s][j]=d+w[i];
                pq.push({dis[s][j],j});
            }
        }
    }
}

struct seg{
    int u,v,w;
};
vector<seg> vec;


int dfn[maxn],low[maxn],timestamp;
// int stk[maxn],top;
// int id[maxn],dcc_cnt;
bool is_bridge[maxn];

void tarjan(int u,int fa){ // fa 为边的编号
    dfn[u]=low[u]=++timestamp;
    // stk[++top]=u;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j,i);
            low[u]=min(low[u],low[j]);
            // 找到桥 <==> dfn[x] < low[y]
            if(dfn[u]<low[j]) is_bridge[w[i]]=is_bridge[w[i^1]]=true;
        }
        else if(i!=(fa^1)) low[u]=min(low[u],dfn[j]);
    }
    // if(dfn[u]==low[u]){
    //     ++dcc_cnt;
    //     int y;
    //     do{
    //         y=stk[top--];
    //         id[y]=dcc_cnt;
    //     } while(y!=u);
    // }
}

void get_bridge(){
    idx=0;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        auto x=vec[i];
        if(dis[1][x.u]+x.w+dis[2][x.v]==dis[1][2]){
            add(x.u,x.v,i),add(x.v,x.u,i);
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i,0);
    }
}


void sol(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w);
        vec.push_back({u,v,w});
    }
    dij(1);

    idx=0;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        add(vec[i].v,vec[i].u,vec[i].w);
    }
    dij(2);

    get_bridge();
    for(int i=0;i<vec.size();i++){
        int u=vec[i].u,v=vec[i].v,w=vec[i].w;
        if(dis[1][v]+dis[2][u]+w<dis[1][2]) cout<<"HAPPY"<<endl;
        else if(is_bridge[i]) cout<<"SAD"<<endl;
        else cout<<"SOSO"<<endl;
    }
    return ;
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
