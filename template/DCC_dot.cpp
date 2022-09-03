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

const int maxn=5e4+10;
int h[maxn],ne[maxn],e[maxn],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfn[maxn],low[maxn],timestamp;
int root,ans;
int n,m;

void tarjan(int u){
    dfn[u]=low[u]=++timestamp;
    int cnt=0;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
            if(low[j]>=dfn[u]) cnt++;
        } 
        else low[u]=min(low[u],dfn[j]);
    }
    if(u!=root) cnt++;
    ans=max(ans,cnt);
}

// 缩点
int dfn[M],low[M],timestamp=0;
int stk[N],top=0;
vector<int> dcc[M]; //记录每个连通块内的点
bool cut[N];
int dcc_cnt=0;  //记录每个点是否是割点
void tarjan(int u){
    dfn[u]=low[u]=++timestamp;
    stk[++top]=u;

    if(u==root&&h[u]==-1){ //说明此时u是孤立点
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return ;
    }

    int cnt=0;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
            if(dfn[u]<=low[j]){
                cnt++;
                if(u!=root||cnt>1)  cut[u]=true;
                dcc_cnt++;
                int y;
                do{
                    y=stk[top--];
                    dcc[dcc_cnt].push_back(y);
                }while(y!=j);
                dcc[dcc_cnt].push_back(u);
            }
        }
        else low[u]=min(low[u],dfn[j]);
    }
}

void sol(){
    while(cin>>n>>m,n||m){
        memset(dfn,0,sizeof dfn);
        memset(h,-1,sizeof h);
        idx=timestamp=0;
        while(m--){
            int a,b; cin>>a>>b;
            add(a,b),add(b,a);
        }
        ans=0;
        int cnt=0;
        for(root=0;root<n;root++){
            if(!dfn[root]){
                cnt++;
                tarjan(root);
            }
        }
        cout<<ans+cnt-1<<endl;
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
