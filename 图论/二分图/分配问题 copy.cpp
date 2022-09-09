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
int n,m,S,T;
const int maxn=110,maxm=5210;
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

void sol(){
    cin>>n;
    S=0,T=2*n+1;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            add(i,n+j,1,x);
        }
    }
    for(int i=1;i<=n;i++){
        add(S,i,1,0);
        add(i+n,T,1,0);
    }
    int flow,cost;
    EK(flow,cost);

    // 我们可以先求最小费用最大流，然后将所有边的费用取反去求最大费用最大流。
    for(int i=0;i<idx;i+=2){
        e[i].c+=e[i^1].c,e[i^1].c=0;
        e[i].w=-e[i].w,e[i^1].w=-e[i^1].w;
    }
    int flow1,cost1;
    EK(flow1,cost1);

    cout<<cost<<endl<<-cost1<<endl;
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
