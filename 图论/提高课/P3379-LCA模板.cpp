#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int n,m,s;
const int maxn=5e5+10;
int p[maxn];
int h[maxn],e[maxn],ne[maxn],idx;
vector<pii> ask[maxn];
int st[maxn],ans[maxn];
int din[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void tarjan(int u){
    // for(int i=1;i<=n;i++) cout<<st[u]<<' '<<endl;
    // cout<<endl;
    // cout<<endl;
    // cout<<u<<endl;
    st[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        cout<<j<<endl;
        if(st[j]) continue;
        tarjan(j);
        p[j]=u;
    }

    for(auto x:ask[u]){
        int y=x.first, id=x.second;
        if(st[y]==2){
            int anc=find(y);
            ans[id]=anc;
            cout<<ans[id]<<' '<<id<<endl;
        }
    }
    st[u]=2;
}

int main(){
    cin>>n>>m>>s;
    memset(h,-1,sizeof h);
    for(int i=1;i<n;i++){
        int x,y; cin>>x>>y;
        add(y,x),add(y,x);
        din[y]++;
    }

    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;
        ask[a].push_back({b,i});
        ask[b].push_back({a,i});
    }


    for(int i=1;i<=n;i++) p[i]=i;
    // int root;
    // for(int i=1;i<n;i++) if(din[i]==0) root=i;
    // cout<<root;
    tarjan(s);

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}