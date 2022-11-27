#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3fLL
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=2e5+10,maxm=4e5+10;
struct Graph{
    int h[maxn],ne[maxn],e[maxm],w[maxm],idx;
    Graph(){
        memset(h,-1,sizeof h);
    }
    void add(int a,int b,int c){
        e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
    }
} G,inv_G;
 
int n,m;
int S,T;

int dis[maxn],inv_dis[maxn];
bool st[maxn];
void Dij(Graph &G){
    memset(st,0,sizeof st);
    memset(dis,0x3f,sizeof dis);
    dis[S]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,S});

    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int ver=t.second,dist=t.first;
        if(st[ver]) continue;
        st[ver]=1;
        for(int i=G.h[ver];~i;i=G.ne[i]){
            int j=G.e[i];
            if(st[j]) continue;
            if(dis[j]>dis[ver]+G.w[i]){
                dis[j]=dist +G.w[i];
                pq.push({dis[j],j});
            }
        }
    }
}
void inv_Dij(Graph &G){
    memset(st,0,sizeof st);
    memset(inv_dis,0x3f,sizeof inv_dis);
    inv_dis[T]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,T});

    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int ver=t.second,dist=t.first;
        if(st[ver]) continue;
        st[ver]=1;
        for(int i=G.h[ver];~i;i=G.ne[i]){
            int j=G.e[i];
            if(st[j]) continue;
            if(inv_dis[j]>inv_dis[ver]+G.w[i]){
                inv_dis[j]=dist +G.w[i];
                pq.push({inv_dis[j],j});
            }
        }
    }
}
int d[maxn];


// ---------------------
ll tree[maxn<<2];
int ans;
void update(int x,int l,int r,int L,int R,long long val){
    if(L<=l && r<=R){
        tree[x]=min(tree[x],1ll*val);
        return;
    }
    int mid=(l+r)/2;
    if(L<=mid)update(x<<1,l,mid,L,R,val);
    if(R>mid)update(x<<1|1,mid+1,r,L,R,val);
}
void query(int x,int l,int r,int pos){
    ans=min(ans,tree[x]);
    if(l==r)return;
    int mid=(l+r)/2;
    if(pos<=mid)query(x<<1,l,mid,pos);
    else query(x<<1|1,mid+1,r,pos);
}
// ---------------------

void sol(){
    cin>>n>>m>>S>>T;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        G.add(u,v,w),inv_G.add(v,u,w);
        d[v]++;
    }

    Dij(G);
    inv_Dij(inv_G);

    queue<int> q;
    vector<int> top(n+1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(d[i]==0) q.push(i);
    }
    while(q.size()){
        int t=q.front(); q.pop();
        top[t]=++cnt;
        for(int i=G.h[t];~i;i=G.ne[i]){
            int j=G.e[i];
            d[j]--;
            if(!d[j]) q.push(j);
        }
    }
    memset(tree,0x3f,sizeof(tree));
    for(int i=1;i<=n;i++){
        for(int j=G.h[i];~j;j=G.ne[j]){
            int x=i,y=G.e[j];
            if(dis[x]!=inf && inv_dis[y]!=inf && top[x]+1<top[y]){
                update(1,1,n,top[x]+1,top[y]-1,dis[x]+inv_dis[y]+G.w[j]);
            }
        }
    }
    int ask; cin>>ask;
    while(ask--){
        int x; cin>>x;
        if(dis[x]==inf||inv_dis[x]==inf) cout<<dis[T]<<endl;
        else{
            ans=inf;
            query(1,1,n,top[x]);
            cout<<(ans==inf?-1:ans)<<endl;
        }
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
