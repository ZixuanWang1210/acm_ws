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

const int maxn=5e6+10;
int h[maxn],ne[maxn],e[maxn],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfn[maxn],low[maxn],timestamp;
int stk[maxn],top;
bool cut[maxn];
int dcc_cnt;
int root;
int a,b;
void tarjan(int u){
    dfn[u]=low[u]=++timestamp;
    stk[++top]=u;

    if(u==root&&h[u]==-1){
        dcc_cnt++;
        return;
    }

    int cnt=0;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
            if(low[j]>=dfn[u]&&u!=a&&dfn[b]>=dfn[j]) cut[u]=true;
        }
        else low[u]=min(low[u],dfn[j]);
    }
}

int n,m;

void sol(){
    cin>>n;
    int x,y;
    memset(h,-1,sizeof h);
    while(cin>>x>>y,x|y){
        add(x,y),add(y,x);
    }
    cin>>a>>b;
    tarjan(a);
    // for(root=1;root<=n;root++){
    //     if(!dfn[root]){
    //         tarjan(root);
    //     }
    // }
    for(int i=1;i<=n;i++){
        if(cut[i]){
            cout<<i<<endl;
            return;
        }
    }
    cout<<"No solution"<<endl;
    return;

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
