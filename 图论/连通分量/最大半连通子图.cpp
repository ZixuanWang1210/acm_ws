#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define ll long long
// #define int long long

using namespace std;

const int maxm=2e6+10,maxn=1e5+10;
int h[maxn],ne[maxm],e[maxm],w[maxn],idx,hs[maxn];
void add(int h[],int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int n,m,mod;

int dfn[maxn],low[maxn],timestamp;
int stk[maxn],top;
int id[maxn],scc_cnt,siz[maxn];
bool in_stk[maxn];
void tarjan(int u){
    dfn[u]=low[u]=++timestamp;
    stk[++top]=u,in_stk[u]=true;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
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

ll g[maxn],f[maxn];

void sol(){
    memset(h,-1,sizeof h);
    memset(hs,-1,sizeof hs);
    cin>>n>>m>>mod;
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;
        add(h,a,b);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }

    unordered_set<ll> s;
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int a=id[i],b=id[k];
            ll has=a*1000000ll+b;
            if(a!=b&&!s.count(has)){
                add(hs,a,b);
                s.insert(has);
            }
        }
    }

    for(int i=scc_cnt;i>0;i--){
        if(!f[i]){
            f[i]=siz[i];
            g[i]=1;
        }

        for(int j=hs[i];~j;j=ne[j]){
            int k=e[j];
            if(f[k]<f[i]+siz[k]){
                f[k]=f[i]+siz[k];
                g[k]=g[i];
            }
            else if(f[k]==f[i]+siz[k]){
                g[k]=(g[k]+g[i])%mod;
            }
        }
    }

    ll maxf=0,sum=0;
    for(int i=1;i<=scc_cnt;i++){
        if(f[i]>maxf){
            maxf=f[i];
            sum=g[i];
        }
        else if(f[i]==maxf){
            sum=(sum+g[i])%mod;
        }
    }
    cout<<maxf<<endl;
    cout<<sum<<endl;

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
