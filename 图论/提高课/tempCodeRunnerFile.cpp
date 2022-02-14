#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e5+10;
int e[maxn],ne[maxn],h[maxn],idx;
int dfn[maxn],low[maxn],timestamp;
stack<int> stk;
bool in_stk[maxn];
int id[maxn],scc_cnt,size_scc[maxn];
int dout[maxn];
int n,m;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx ++;
}

void tarjan(int u){
    low[u]=dfn[u]=++ timestamp;
    stk.push(u);
    in_stk[u]=true;

    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
        }
        else if(in_stk[j]){
            low[u]=min(low[u],dfn[j]);
        }
        // low[u]=min(low[u],low[j]);
    }

    if(dfn[u]==low[u]){
        int y;
        ++ scc_cnt;
        do{
            y=stk.top(); stk.pop();
            in_stk[y]=false;
            id[y]=scc_cnt;
            size_scc[scc_cnt] ++;
        } while(y!=u);
    }
}



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        add(a,b);
    }

    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int a=id[i];
            int b=id[k];
            if(a!=b) dout[a] ++;
        }
    }

    int zeros=0,sum=0;
    for(int i=1;i<=scc_cnt;i++){
        if(!dout[i]){
            zeros ++;
            sum+=size_scc[i];
            if(zeros>1){
                sum=0;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
