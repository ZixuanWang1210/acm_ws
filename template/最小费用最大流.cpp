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

const int maxn=5005,maxm=5e5+10;

int n,m,S,T;
int h[maxn],idx;
struct node{
    int v,c,w,ne;
} e[maxm];

void add(int u,int v,int c,int w){
    e[idx]={v,c,w,h[u]},h[u]=idx++;
    e[idx]={u,0,-w,h[v]},h[v]=idx++;
}

int dis[maxn],lim[maxn],fa[maxn];
bool vis[maxn];

bool spfa(){
    memset(dis,0x3f,sizeof dis);
    memset(lim,0,sizeof lim);
    queue<int> q;
    q.push(S),dis[S]=0,lim[S]=inf,vis[S]=true;
    while(q.size()){
        int t=q.front();
        q.pop();
        vis[t]=false;
        for(int i=h[t];~i;i=e[i].ne){
            int j=e[i].v;
            if(dis[j]>dis[t]+e[i].w&&e[i].c){
                dis[j]=dis[t]+e[i].w;
                fa[j]=i;
                lim[j]=min(lim[t],e[i].c);
                if(!vis[j]){
                    vis[j]=true;
                    q.push(j);
                }
            }
        }
    }
    return lim[T]>0;
}

void EK(int &flow,int &cost){
    flow=cost=0;
    while(spfa()){
        int t=lim[T];
        flow+=t,cost+=t*dis[T];
        for(int i=T;i!=S;i=e[fa[i]^1].v){
            e[fa[i]].c-=t,e[fa[i]^1].c+=t;
        }
    }
}

// 最大费用最大流：边权取反，cost取反！
void sol(){
    memset(h,-1,sizeof h);
    cin>>n>>m>>S>>T;
    while(m--){
        int u,v,c,w;
        cin>>u>>v>>c>>w;
        add(u,v,c,w);
    }
    int flow,cost;
    EK(flow,cost);
    cout<<flow<<' '<<cost<<endl;
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
