#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

int n,m;
const int maxn=2e6+10,maxm=2e9+7;
int h[maxn],ne[maxn],e[maxn],idx;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfn[maxn],low[maxn],timestamp;
int stk[maxn],top;
int id[maxn],scc_cnt,siz[maxn];
bool in_stk[maxn];

int v[maxn],val[maxn];
int op[maxn];
int pre[maxn];
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
            v[scc_cnt]+=val[y];
        } while(y!=u);
    }
}

bool check(int x){
    int sum=0;
    memcpy(op,v,sizeof v);
    for(int i=1;i<=scc_cnt;i++){
        int need=siz[i]*x;
        int del=op[i]-need;
        if(del>=0){
            continue;
        }
        else{
            if(pre[i]!=0){
                op[pre[i]]+=del;
            }
            else{
                sum+=-del;
            }
        }
        if(sum>m) return false;
    }
    return true;
}

void sol(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x!=-1&&x!=i)
            add(x,i);
    }    

    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }

    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int vv=e[j];
            int u=id[i],v=id[vv];
            if(u!=v){
                pre[v]=u;
            }
        }
    }
    
    int l=0,r=1e9,ans=1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
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
