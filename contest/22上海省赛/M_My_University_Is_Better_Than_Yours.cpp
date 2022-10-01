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

int n,m;
const int maxn=1e7+10;
int h[maxn],ne[maxn],e[maxn],idx;
int dp[maxn];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int hh[maxn],nee[maxn],ee[maxn],idxx;
void add1(int a,int b){
    ee[idxx]=b,nee[idxx]=hh[a],hh[a]=idxx++;
}
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
int din[maxn],dout[maxn];
void sol(){
    memset(h,-1,sizeof h);
    memset(hh,-1,sizeof hh);
    cin>>n>>m;    
    for(int i=1;i<=m;i++){
        string s;
        getline(cin,s);
        getline(cin,s);
        // cout<<s<<endl;
        stringstream ss(s);
        int re=0,now=0;
        ss>>re;
        while(ss>>now){
            add(now,re);
            // cout<<"add: "<<re<<' '<<now<<endl;
            re=now;
        }
        // cout<<endl;
    }

    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    set<pii> seg;
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int xx=id[i],yy=id[k];
            if(xx!=yy){
                // dout[xx]++,din[yy]++;
                // add1(xx,yy);
                seg.insert({xx,yy});
            }
        }
    }
    for(auto x:seg){
        // cout<<"add1: "<<x.first<<' '<<x.second<<endl;
        din[x.second]++;
        add1(x.first,x.second);
    }
    // cout<<scc_cnt<<endl;
    // cout<<"din: "<<endl;
    // for(int i=1;i<=scc_cnt;i++){
    //     cout<<din[i]<<' ';
    // }
    // cout<<endl;

    stack<int> stk;
    for(int i=1;i<=scc_cnt;i++){
        dp[i]=siz[i];
        if(din[i]==0){
            stk.push(i);
        }
    }
    while(stk.size()){
        int t=stk.top(); stk.pop();
        for(int i=hh[t];~i;i=nee[i]){
            int j=ee[i];
            dp[j]+=dp[t];
            // cout<<j<<' '<<t<<' '<<dp[j]<<endl;
            din[j]--;
            if(din[j]==0) stk.push(j);
        }
    }
    // cout<<scc_cnt<<endl;
    // for(int i=1;i<=scc_cnt;i++){
    //     cout<<dp[i]<<' ';
    // }
    // cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<dp[id[i]]-1<<' ';
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
