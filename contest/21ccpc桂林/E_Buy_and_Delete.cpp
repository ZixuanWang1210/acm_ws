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

int n,m,c;
const int maxn=5000+10;
int dis[2100][2100];
struct node{
    int u,v,w;
} seg[2*maxn];
int st[maxn];
int h[maxn],ne[maxn],w[maxn],e[maxn],idx;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dij(int s,int dis[]){
    memset(dis, 0x7f, maxn * 4);
    memset(st,0,sizeof st);
    // for(int i=1;i<=n;i++){
    //     dis[i]=inf,st[i]=0;
    // }
    priority_queue<pii> pq;
    dis[s]=0;
    pq.push({0,s});

    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int d=t.first,ver=t.second;
        if(st[ver]) continue;
        st[ver]=true;

        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(st[j]) continue;
            if(dis[j]>dis[ver]+w[i]){
                dis[j]=dis[ver]+w[i];
                pq.push({-dis[j],j});
            }
        }
    }
}
bool ok=false;
int tot;
void sol(){
    cin>>n>>m>>tot;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        seg[i]={u,v,w};
        add(u,v,w);
        if(tot>=w) ok=true;
    }
    if(!ok){
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
        dij(i,dis[i]);

    int res=inf;
    for(int i=1;i<=m;i++){
        int u=seg[i].u,v=seg[i].v,w=seg[i].w;
        res=min(res,w+dis[v][u]);
    }
    cout<<(tot<res?"1":"2")<<endl;

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
