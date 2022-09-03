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

const int maxn=4e4+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int n,m;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfn[maxn],low[maxn],timestamp;
int stk[maxn],top;
int id[maxn],dcc_cnt;
bool is_bridge[maxn];
int d[maxn];

void tarjan(int u,int fa){ // fa 为边的编号
    dfn[u]=low[u]=++timestamp;
    stk[++top]=u;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j,i);
            low[u]=min(low[u],low[j]);
            // 找到桥 <==> dfn[x] < low[y]
            if(dfn[u]<low[j]) is_bridge[i]=is_bridge[i^1]=true;
        }
        else if(i!=(fa^1)) low[u]=min(low[u],dfn[j]);
    }
    if(dfn[u]==low[u]){
        ++dcc_cnt;
        int y;
        do{
            y=stk[top--];
            id[y]=dcc_cnt;
        } while(y!=u);
    }
}


void sol(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b; cin>>a>>b;
        add(a,b),add(b,a);
    }

    tarjan(1,-1);

    for(int i=0;i<idx;i++)
        if(is_bridge[i]) d[id[e[i]]]++;
    
    int cnt=0;
    for(int i=1;i<=dcc_cnt;i++)
        if(d[i]==1) cnt++;

    // 有向图 max(cnt_{din[i]==0},cnt_{dout[i]==0})
    // 无向图 (cnt_{d[i]==1}+1)/2
    cout<<(cnt+1)/2<<endl;
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
