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

const int maxn=4e5+10;
int h[maxn],ne[maxn],e[maxn],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
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

map<string,int> mp;
vector<pair<string,string>> v;
int n,m,tt;
void sol(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        string s1,s2; cin>>s1>>s2;
        v.push_back({s1,s2});
        if(!mp[s1]) mp[s1]=++tt;
        if(!mp[s2]) mp[s2]=++tt;
        add(mp[s1],mp[s2]);
    }

    cin>>m;
    for(int i=1;i<=m;i++){
        string s1,s2; cin>>s1>>s2;
        add(mp[s2],mp[s1]);
    }
    
    for(int i=1;i<=2*n;i++){
        if(!dfn[i]) tarjan(i);
    }

    for(auto x:v){
        int xx=mp[x.first],yy=mp[x.second];
        if(id[xx]==id[yy]) cout<<"Unsafe"<<endl;
        else cout<<"Safe"<<endl;
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
