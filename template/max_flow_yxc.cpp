#include<bits/stdc++.h>
using namespace std;
const int INF=0x3fffffff;
int n,p,t;
struct edge{
    int v,w,nxt,num;
    edge(){v=w=nxt=0;}
    edge(int _v,int _w,int _nxt){v=_v;w=_w;nxt=_nxt;}
};
struct graph{
    static const int MAXN=500,MAXM=5000;
    edge g[MAXM*2+5];
    int tot,head[MAXN+5];
    graph(){tot=0;}
    void insert_edge(int u,int v,int w,int num){
        g[++tot]=edge(v,w,head[u]);head[u]=tot;g[tot].num=num;
        g[++tot]=edge(u,w,head[v]);head[v]=0;g[tot].num=-num;
    }
    int lev[MAXN+5],_head[MAXN+5];
    bool bfs(){
        for(int i=1;i<=n;i++)lev[i]=0;
        queue<int> q;
        q.push(1);lev[1]=1;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=head[u];i;i=g[i].nxt){
                int v=g[i].v,w=g[i].w;
                if(!lev[v]&&w){
                    q.push(v);
                    lev[v]=lev[u]+1;
                }
            }
        }
        if(lev[n])return true;
        else return false;
    }
    int dfs(int u,int in){
        if(u==n)return in;
        int out=0;
        for(int &i=_head[u];i;i=g[i].nxt){
            int v=g[i].v,w=g[i].w;
            if(w&&lev[v]==lev[u]+1){
                int nxt=dfs(v,min(w,in));
                if(nxt){
                    in-=nxt;
                    out+=nxt;
                    g[i].w-=nxt;
                    g[i^1].w+=nxt;
                }
            }
        }
        if(out==0)lev[u]=INF;
        return out;
    }
    int Dinic(){
        int res=0;
        while(bfs()){
            for(int i=1;i<=n;i++)_head[i]=head[i];
            while(int tmp=dfs(1,INF)){
                res+=tmp;
            }
        }
        return res;
    }
};
graph g;
int main(){

    return 0;
}
