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
void sol(){
    // 缩点
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    // 遍历连通域
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int xx=id[i],yy=id[k];
            if(xx!=yy) dout[xx]++,din[yy]++;
        }
    }
    // 建新图
    unordered_set<ll> s;
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[i];
            int a=id[i],b=id[k];
            ll has=a*1000000ll+b;
            if(a!=b&&!s.count(has)){
                add(hs,a,b);
                s.insert(has);
            }
        }
    }
    // 拓扑排序，scc_cnt的编号递减顺序就是拓扑序
    for(int i=scc_cnt;i>0;i--){

    }

}