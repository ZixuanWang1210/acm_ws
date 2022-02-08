#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define debug_(ch, i) printf(#ch"[%d]: %d\n", i, ch[i])
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e5;
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
    // 哨兵depth[0] = 0: 如果从i开始跳2^j步会跳过根节点 
    // fa[fa[j][k-1]][k-1] = 0
    // 那么fa[i][j] = 0 depth[fa[i][j]] = depth[0] = 0
    while(q.size()){
        int t=q.front(); q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dep[j]) continue;
            dep[j]=dep[t]+1;
            q.push(j);
            fa[j][0]=t;
            for(int k=1;k<=18;k++){ //注意边界
                fa[j][k]=fa[fa[j][k-1]][k-1];
            }
             /*
            举个例子理解超过根节点是怎么超过的
            因为我们没有对根节点fa[1][0]赋值,那么fa[1][0] = 0;
                 1
                / \
               2   3 
            fa[1][0] = 0;
            fa[2][0] = 1;
            fa[2][1] = fa[fa[2][0]][0] = fa[1][0] = 0;
            */
        }
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int k=18;k>=0;k--)
        if(dep[fa[x][k]]>=dep[y])
            x=fa[x][k];
        
    
    if(x==y) return x;
    for(int k=18;k>=0;k--){
        if(fa[x][k]!=fa[y][k]){
            x=fa[x][k];
            y=fa[y][k];
        }
    }

    return fa[x][0];
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
