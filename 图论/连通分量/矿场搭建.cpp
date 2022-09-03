#include<bits/stdc++.h>
using namespace std;
#define N 1010
#define M 1010
typedef unsigned long long ULL;

int h[N],ne[M],e[M],idx=0;
int dfn[M],low[M],timestamp=0;
int stk[N],top=0;
vector<int> dcc[M]; //记录每个连通块内的点
bool cut[N];
int dcc_cnt=0;  //记录每个点是否是割点
int n,m,root;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfn[M],low[M],timestamp=0;
int stk[N],top=0;
vector<int> dcc[M]; //记录每个连通块内的点
bool cut[N];
int dcc_cnt=0;  //记录每个点是否是割点
void tarjan(int u){
    dfn[u]=low[u]=++timestamp;
    stk[++top]=u;

    if(u==root&&h[u]==-1){ //说明此时u是孤立点
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return ;
    }

    int cnt=0;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
            if(dfn[u]<=low[j]){
                cnt++;
                if(u!=root||cnt>1)  cut[u]=true;
                dcc_cnt++;
                int y;
                do{
                    y=stk[top--];
                    dcc[dcc_cnt].push_back(y);
                }while(y!=j);
                dcc[dcc_cnt].push_back(u);
            }
        }
        else low[u]=min(low[u],dfn[j]);
    }
}

int main(){
    int num=0;
    while(cin >> n,n){
        num++;
        for(int i=0;i<=dcc_cnt;i++) dcc[i].clear();
        memset(h,-1,sizeof h);
        memset(dfn,0,sizeof dfn);
        memset(cut,0,sizeof cut);
        top=idx=dcc_cnt=timestamp=0;

        int dot=0;
        for(int i=1;i<=n;i++){
            int a,b;
            cin >> a >> b;
            dot=max(dot,a),dot=max(dot,b);
            add(a,b),add(b,a);
        }

        for(root=1;root<=dot;root++)
            if(!dfn[root])
                tarjan(root);

        int res=0;
        ULL sum=1;

        for(int i=1;i<=dcc_cnt;i++){
            int cnt=0;  //统计连通块内割点的个数
            for(int j=0;j<dcc[i].size();j++)
                if(cut[dcc[i][j]])
                    cnt++;

            if(!cnt){
                if (dcc[i].size() > 1)res+=2,sum*=dcc[i].size()*(dcc[i].size()-1)/2; //如果不是孤立点
                else res++;  //如果是孤立点
            }
            else if(cnt==1){
                res+=1;
                sum*=dcc[i].size()-1;
            }
        }
        printf("Case %d: %d %lld\n",num,res,sum);
    }
    return 0;
}