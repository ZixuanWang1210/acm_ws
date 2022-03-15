#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n,m;
const int maxn=110;
int g[maxn][maxn];
int d[maxn][maxn];
int path[maxn],cnt;
int pos[maxn][maxn];

void get_path(int i,int j){
    if(pos[i][j]==0) return;

    int k=pos[i][j];
    get_path(i,k);
    path[cnt++]=k;
    get_path(k,j);
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=n;i++){
        g[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u][v]=g[v][u]=min(g[u][v],w);
    }
    int res=0x3f3f3f3f;
    memcpy(d,g,sizeof d);
    for(int k=1;k<=n;k++){
        for(int i=1;i<k;i++){
            for(int j=i+1;j<k;j++){
                if((long long)d[i][j]+g[j][k]+g[k][i]<res){
                    res=d[i][j]+g[j][k]+g[k][i];
                    cnt=0;
                    path[cnt++]=k;
                    path[cnt++]=i;
                    get_path(i,j);
                    path[cnt++]=j;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    pos[i][j]=k;
                }
            }
        }
    }
    if (res == 0x3f3f3f3f) puts("No solution.");
    else
    {
        for (int i = 0; i < cnt; i ++ ) cout << path[i] << ' ';
        cout << endl;
    }

    return 0;
}
