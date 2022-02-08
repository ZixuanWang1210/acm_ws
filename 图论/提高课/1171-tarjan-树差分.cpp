#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<int,int>
using namespace std;

const int maxn=5e5+10;
int n,m;
int w[maxn],e[maxn],ne[maxn],h[maxn],idx; //邻接表
int p[maxn]; //并查集
vector<pii> ask[10010]; //离线存储询问
int dis[maxn],st[maxn],ans[maxn]; //tarjan距离


int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){ //dfs无限递归也会MLE
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue; //防止走回父节点
        dis[j]=dis[u]+w[i]; //计算距离
        dfs(j,u);
    }
}

/*
在深度优先遍历时,将所有点分成三大类:
[0] 还未搜索到的点
[1] 正在搜索的分支
[2] 已经遍历过,且回溯过
*/
void tarjan(int u){
    st[u]=1;
    // u这条路上的根节点的左下的点用并查集合并到根节点
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(st[j]) continue;
        tarjan(j);
        p[j]=u; //从左下回溯后把左下的点合并到根节点
    }

    // 对于当前点u 搜索所有的询问，查看是否可以得出结果
    for(auto item:ask[u]){
        int y=item.first,id=item.second;
        if(st[y]==2){ //该点已被回溯，也就是经过了并查集的合并
            int anc=find(y);
            ans[id]=dis[u]+dis[y]-dis[anc]*2; //保持原本次序输出
        }
    }
    st[u]=2; //点u已经搜索完且要回溯了 就把st[u]标记为2 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++){
        int x,y,k; cin>>x>>y>>k;
        add(x,y,k),add(y,x,k);
    }

    //记录询问
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        if(x==y) continue;
        ask[x].push_back({y,i});
        ask[y].push_back({x,i});
    }

    for(int i=1;i<=n;i++) p[i]=i;

    dfs(1,-1);
    tarjan(1);
    for(int i=0;i<m;i++) cout<<ans[i]<<endl;

    return 0;
}
