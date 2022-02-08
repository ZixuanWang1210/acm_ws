#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e5+10;
int n,m;
int ne[maxn],e[maxn],h[maxn],idx;
int fa[maxn][21],dep[maxn];
int root;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void bfs(){
    queue<int>q;
    q.push(root);
    dep[root]=1,dep[0]=0;
    while(q.size()){
        int t=q.front(); q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dep[j]) continue;
            dep[j]=dep[t]+1;
            q.push(j);
            fa[j][0]=t;
            for(int k=1;k<=21;k++) fa[i][k]=fa[fa[i][k-1]][k-1];
        }
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int k=21;k>=0;k--){
        if(dep[fa[x][k]]>=dep[y]){
            x=fa[x][k];
        }
    }
    if(x==y) return x;
    for(int k=21;k>=0;k--){
        if(fa[x][k]!=fa[y][k]){
            x=fa[x][k];
            y=fa[y][k];
        }
    }

    return fa[x][0];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        if(b==-1) root=a;
        else add(a,b),add(b,a);
    }
    
    bfs();

    cin>>m;
    while(m--){
        int a,b; cin>>a>>b;
        int ans=lca(a,b);
        if(ans==a) cout<<1<<endl;
        else if(ans==b) cout<<2<<endl;
        else cout<<0<<endl;
    }

    return 0;
}
