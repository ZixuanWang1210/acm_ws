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

const int maxn=1e6+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],hs[maxn],idx;
int n,m;
void add(int h[],int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfn[maxn],low[maxn],timestamp;
int stk[maxn],top;
int id[maxn],scc_cnt,siz[maxn];
bool in_stk[maxn];
void tarjan(int u){
    dfn[u]=low[u]=timestamp++;
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

int dis[maxn];
int k;
void sol(){
    cin>>n>>k;
    memset(h,-1,sizeof h);
    memset(hs,-1,sizeof hs);

    for(int i=1;i<=n;i++) add(h,0,i,1);
    while(k--){
        int x,a,b; cin>>x>>a>>b;
        if(x==1) add(h,b,a,0),add(h,a,b,0);
        else if(x==2) add(h,a,b,1);
        else if(x==3) add(h,b,a,0);
        else if(x==4) add(h,b,a,1);
        else add(h,a,b,0);
    }

    tarjan(0);
    bool ok=true;
    for(int i=0;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int a=id[i],b=id[k];
            if(a==b){
                if(w[j]>0){
                    ok=false;
                    break;
                }
            }
            else add(hs,a,b,w[j]);
        }
        if(!ok) break;
    }
    if(!ok) cout<<-1<<endl;
    else{
        for(int i=scc_cnt;i;i--){
            for(int j=hs[i];~j;j=ne[j]){
                int k=e[j];
                dis[k]=max(dis[i]+w[j],dis[k]);
            }
        }
        ll res=0;
        for(int i=1;i<=scc_cnt;i++){
            res+=(ll)dis[i]*siz[i];
        }
        cout<<res<<endl;
    }
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
