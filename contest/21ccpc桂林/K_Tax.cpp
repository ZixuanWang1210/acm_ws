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

int n,m;
const int maxn=10000;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int c[maxn],cnt[maxn];
int dis[maxn];
bool st[maxn];
int ans[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void bfs(){
    memset(dis,0x3f,sizeof dis);
    queue<int> q;
    q.push(1);
    dis[1]=0;
    
    while(q.size()){
        int t=q.front(); q.pop();
        if(st[t]) continue;
        st[t]=true;

        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+1){
                dis[j]=dis[t]+1;
                q.push(j);
            }
        }
    }
}

int sum;
void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        if(dis[j]==dis[u]+1){
            cnt[w[i]]++;
            sum+=cnt[w[i]]*c[w[i]];
            ans[j]=min(ans[j],sum);
            dfs(j,u);
            sum-=cnt[w[i]]*c[w[i]];
            cnt[w[i]]--;
        }
    }
}

void sol(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    memset(ans,0x3f,sizeof ans);
    for(int i=1;i<=m;i++) cin>>c[i];
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w),add(v,u,w);
    }
    bfs();
    dfs(1,-1);
    for(int i=2;i<=n;i++){
        cout<<ans[i]<<endl;
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
