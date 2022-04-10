#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=2e6+10;
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
int c[maxn],d[maxn];
int n,m;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa,int col){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        c[w[i]]=col;
        col=5-col;
        dfs(j,u,col);        
    }
}

void sol(){
    int n; cin>>n;
    for(int i=0;i<4*n;i++){
        h[i]=-1;
        e[i]=0;
        ne[i]=0;
        w[i]=0;
        c[i]=0;
        d[i]=0;
    }
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        add(u,v,i),add(v,u,i);
        d[u]++,d[v]++;
    }

    for(int i=1;i<=n;i++){
        if(d[i]>2){
            cout<<-1<<endl;
            return;
        }
    }

    dfs(1,-1,2);
    for(int i=1;i<=n-1;i++){
        cout<<c[i]<<' ';
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) sol();


    return 0;
}
