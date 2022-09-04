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

int n;
const int maxn=2000;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfn[maxn],low[maxn],timestamp;
int stk[maxn],top;
int id[maxn],scc_cnt,siz[maxn];
bool in_stk[maxn];
int din[maxn],dout[maxn];
void tarjan(int u){
    dfn[u]=low[u]=++timestamp;
    stk[++top]=u,in_stk[u]=true;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[j],low[u]);
        }
        else if(in_stk[j]){
            low[u]=min(low[u],dfn[j]);
        }
    }
    if(dfn[u]==low[u]){
        ++scc_cnt;
        int y;
        do{
            y=stk[top--];
            in_stk[y]=false;
            id[y]=scc_cnt;
            siz[scc_cnt]++;
        } while(y!=u);
    }
}

void sol(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int x;
        while(cin>>x,x){
            add(i,x);
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }

    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int xx=id[i],yy=id[k];
            if(xx!=yy) dout[xx]++,din[yy]++;
        }
    }

    int src=0,des=0;
    for(int i=1;i<=scc_cnt;i++){
        if(!din[i]) src++;
        if(!dout[i]) des++;
    }
    cout<<src<<endl;
    if(scc_cnt==1) cout<<0<<endl;
    else cout<<max(src,des)<<endl;
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
