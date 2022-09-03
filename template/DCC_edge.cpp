int dfn[maxn],low[maxn],timestamp;
int stk[maxn],top;
int id[maxn],dcc_cnt;
bool is_bridge[maxn];
int d[maxn];

void tarjan(int u,int fa){ // fa 为边的编号
    dfn[u]=low[u]=++timestamp;
    stk[++top]=u;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j,i);
            low[u]=min(low[u],low[j]);
            // 找到桥 <==> dfn[x] < low[y]
            if(dfn[u]<low[j]) is_bridge[i]=is_bridge[i^1]=true;
        }
        else if(i!=(fa^1)) low[u]=min(low[u],dfn[j]);
    }
    if(dfn[u]==low[u]){
        ++dcc_cnt;
        int y;
        do{
            y=stk[top--];
            id[y]=dcc_cnt;
        } while(y!=u);
    }
}

void sol(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b; cin>>a>>b;
        add(a,b),add(b,a);
    }

    tarjan(1,-1);

    for(int i=0;i<idx;i++) //每个新块的度
        if(is_bridge[i]) d[id[e[i]]]++;
    
    int cnt=0;
    for(int i=1;i<=dcc_cnt;i++)
        if(d[i]==1) cnt++;

    // 有向图 max(cnt_{din[i]==0},cnt_{dout[i]==0})
    // 无向图 (cnt_{d[i]==1}+1)/2
    cout<<(cnt+1)/2<<endl;
}
