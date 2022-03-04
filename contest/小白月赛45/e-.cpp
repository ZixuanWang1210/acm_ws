#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
#define pii pair<int,int>
// typedef unsigned long long ull;
#define int long long

using namespace std;

const int maxn=1e6+10;
int idx,h[maxn],ne[maxn],e[maxn],w[maxn];
int cost[maxn];
int n;
bool st[maxn];
int dis[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u){
    int dis=cost[u];
    st[u]=true;
    int now=0;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(st[j]) continue;
        int re=dfs(j);
        // if(re+w[i]>=0) dis+=re+w[i];
        // dis=max(dis,dis+re+w[i]);
        now=max(now,re);
    }
    return now+dis;
}

// void spfa(int root){
//     memset(dis,-0x3f,sizeof dis);
//     // queue<int>q;
//     priority_queue<pii> q;
//     q.push(root);
//     dis[root]=cost[root];

//     st[root]=1;
//     while(q.size()){
//         int t=q.front(); q.pop();
//         // st[t]=false;    
//         for(int i=h[t];~i;i=ne[i]){
//             int j=e[i];
//             if(dis[j]<dis[t]+w[i]+cost[j]){
//                 dis[j]=dis[t]+w[i]+cost[j];
//                 if(!st[j]){
//                     st[j]=true;
//                     q.push(j);
//                 }
//             }
//         }
//     }
//     int ans=-0x3f3f3f3f;
//     for(int i=1;i<=n;i++){
//         ans=max(ans,dis[i]);
//     }
//     cout<<ans<<endl;

// }

signed main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int _max=-1;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
        _max=max(_max,cost[i]);

    }
    memset(h,-1,sizeof h);
    int root=-1;
    for(int i=1;i<n;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w),add(v,u,w);
        if(v+w>0) root=v;
        if(u+w>0) root=u;
    }
    // cout<<1<<endl;
    if(root==-1){
        cout<<_max<<endl;
        return 0;
    }
    spfa(root);
    

    return 0;
}
