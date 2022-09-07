int n,cnt,s,t,maxflow,maxcost,h[Maxx],dis[Maxx],cur[Maxx],a[Maxx];
bool vis[Maxx];
struct Edge{
    int to,lac,flow,cost;
    bool can;
    void insert(int x,int y,int z,int w){
        to=y;lac=h[x];flow=z;cost=w;h[x]=cnt++;
    }
}edge[Maxm],vedge[Maxm];
void add_edge(int x,int y,int z,int w){
    vedge[cnt].insert(x,y,z,w);
    vedge[cnt].insert(y,x,0,-w);
} 
int val=-1;
bool spfa(int s,int t){
    for(int i=1;i<=t;i++) dis[i]=-0x3f3f3f3f;
    memcpy(cur,h,sizeof cur);
    queue<int> q;
    dis[s]=0;vis[s]=1;q.push(s);
    while(!q.empty()){
        int fr=q.front();
        vis[fr]=0;
        q.pop();
        for(int i=h[fr];i!=-1;i=edge[i].lac){
            int to=edge[i].to;
            if(edge[i].flow>0&&!edge[i].can&&dis[to]<dis[fr]+edge[i].cost){
                dis[to]=dis[fr]+edge[i].cost;
                if(!vis[to]){
                    vis[to]=1;
                    q.push(to);
                }
            }
        }
    }
    return dis[t]!=-0x3f3f3f3f;
}
int dfs(int u,int min1){
    if(u==t) return min1;
    int sum=min1;vis[u]=1;
    for(int i=cur[u];i!=-1;i=edge[i].lac){
        int to=edge[i].to;
        if(!vis[to]&&!edge[i].can&&dis[to]==dis[u]+edge[i].cost&&edge[i].flow>0){
            cur[u]=i;
            int ret=dfs(to,min(sum,edge[i].flow));
            sum-=ret;edge[i].flow-=ret;edge[i^1].flow+=ret;
            if(sum==0) break;
        }
    }
    vis[u]=0;
    return min1-sum;
}
void Dinic(int s,int t){
    while(spfa(s,t)){
        int ret=dfs(s,0x3f3f3f3f);
        maxflow+=ret;
        maxcost+=ret*dis[t];
    }
    re ;
}
int main(){
    freopen("YJOI2016.in","r",stdin);
    n=read();
    s=0;t=n<<1|1;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++) add_edge(s,i,1,0);
    for(int j=n+1;j<=n<<1;j++) add_edge(j,t,1,0);
    for(int i=1;i<=n;i++) for(int j=n+1;j<=n*2;j++) add_edge(i,j,1,read());
    memcpy(edge,vedge,sizeof edge);
    Dinic(s,t);
    int cnt1=0;
    for(int i=0;i<cnt;i++){
        int to=edge[i].to,fr=edge[i^1].to; 
        if(!edge[i].flow&&fr<=n&&fr>=1&&to>n&&to<=n*2)
            a[++cnt1]=i;
    }
    printf("%d\n",maxcost);
    int max1=maxcost;
    for(int i=1;i<=cnt1;i++){
        memcpy(edge,vedge,sizeof edge);
        edge[a[i]].can=1;
        edge[a[i]^1].can=1;
        maxflow=0;
        maxcost=0;
        Dinic(s,t);
        if(maxflow==n&&maxcost!=max1)
            printf("%d %d\n",edge[a[i]^1].to,edge[a[i]].to-n);
        edge[a[i]].can=0;
        edge[a[i]^1].can=0;
    }
    re 0;
}