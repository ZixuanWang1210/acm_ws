#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=3e5+10;
int h[maxn],ne[maxn],e[maxn],idx;
int d[maxn],dep[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void init(){
    for(int i=1;i<=maxn;i++){
        e[i]=0,ne[i]=0,h[i]=-1,d[i]=0,dep[i]=0;
        idx=0;
    }
}

void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dep[j]=dep[u]+1; 
        dfs(j,u);
    }
}

void sol(){
    init();
    int n; cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        add(u,v),add(v,u);
        d[u]++,d[v]++;
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        if(dep[i]&1){
            cout<<-d[i]<<' ';
        }
        else cout<<d[i]<<' ';
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
