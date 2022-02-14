#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=2000;
int e[maxn],ne[maxn],h[maxn],idx;
stack<int> stk;
bool in_stk[maxn];
int scc_cnt, scc_size[maxn],id[maxn];
int dfn[maxn],low[maxn],timestamp;
int n;
int dout[maxn],din[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void tarjan(int u){
    low[u]=dfn[u]=++timestamp;
    stk.push(u);
    in_stk[u]=true;

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
        scc_cnt++;
        int y;
        do{
            y=stk.top(); stk.pop(); in_stk[y]=false;
            id[y]=scc_cnt;
            scc_size[scc_cnt]++;
        } while(y!=u);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int t;
        while(cin>>t, t) add(i,t);
    }

    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }

    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int a=id[i];
            int b=id[k];
            if(a!=b) dout[a]++,din[b]++;
        }
    }
    
    int src=0,des=0;
    for(int i=1;i<=scc_cnt;i++){
        if(!din[i]) src++;
        if(!dout[i]) des++;
    }
    cout<<src<<endl;
    if(scc_cnt==1)cout<<'0'<<endl;
    else cout<<max(src,des)<<endl;

    return 0;
}
