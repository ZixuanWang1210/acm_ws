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

const int maxn=4000;
int n,m;
int h[maxn],ne[maxn],w[maxn],e[maxn],idx;
int h1[maxn],ne1[maxn],w1[maxn],e1[maxn],idx1,st1[maxn];
int h2[maxn],ne2[maxn],w2[maxn],e2[maxn],idx2,st2[maxn];
int dis[maxn],cnt[maxn];
bool st[maxn],ok[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void add1(int a,int b){
    e1[idx1]=b,ne1[idx1]=h1[a],h1[a]=idx1++;
}
void add2(int a,int b){
    e2[idx2]=b,ne2[idx2]=h2[a],h2[a]=idx2++;
}

void bfs1(){
    st1[1]=true;
    queue<int> q;
    q.push(1);
    while(q.size()){
        int t=q.front(); q.pop();
        for(int i=h1[t];~i;i=ne1[i]){
            int j=e1[i];
            if(st1[j]) continue;
            else st1[j]=true,q.push(j);
        }
    }
}

void bfs2(){
    st2[n]=true;
    queue<int> q;
    q.push(n);
    while(q.size()){
        int t=q.front(); q.pop();
        for(int i=h2[t];~i;i=ne2[i]){
            int j=e2[i];
            if(st2[j]) continue;
            else st2[j]=true,q.push(j);
        }
    }
}

pii seg[maxn];

bool spfa(){
    queue<int> q;
    memset(dis,0x3f,sizeof dis);
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    dis[1]=0;
    st[1]=true;
    q.push(1);
    while(q.size()){
        int t=q.front(); q.pop(); st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>n) return false;
                if(!st[j]) q.push(j),st[j]=1;
            }
        }
    }
    return true;
}

void sol(){
    cin>>n>>m;
    memset(h1,-1,sizeof h1);
    memset(h2,-1,sizeof h2);
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        seg[i]={u,v};
        add1(u,v);add2(v,u);
    }

    bfs1(),bfs2();
    for(int i=1;i<=n;i++){
        if(st1[i]&&st2[i]) ok[i]=true;
    }
    if(!st1[n]) {cout<<-1<<endl;return;}
    ok[1]=ok[n]=1;
    // for(int i=1;i<=n;i++) cout<<ok[i]<<' ';

    for(int i=1;i<=m;i++){
        int u=seg[i].first,v=seg[i].second;
        if(ok[u]&&ok[v]) add(u,v,-1),add(v,u,9);
    }

    if(!spfa()){cout<<-1<<endl;return;}
    for(int i=1;i<=n;i++) dis[i]*=-1;
    cout<<n<<' '<<m<<endl;
    for(int i=1;i<=m;i++){
        int u=seg[i].first,v=seg[i].second;
        cout<<u<<' '<<v<<' ';
        if(ok[u]&&ok[v]) cout<<dis[v]-dis[u]<<endl;
        else cout<<1<<endl;
    }
    return ;
}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
