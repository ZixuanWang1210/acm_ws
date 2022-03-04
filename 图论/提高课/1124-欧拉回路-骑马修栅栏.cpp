#include<bits/stdc++.h>
using namespace std;

const int maxn=510;
int f;
int n=500;
int g[maxn][maxn];
int d[maxn];
int ans[1100],cnt;

void dfs(int u){
    for(int i=1;i<=n;i++){
        if(g[u][i]){
            g[u][i]--,g[i][u]--;
            dfs(i);
        }
    }
    ans[++cnt]=u;
}

int main(){
    cin>>f;
    while(f--){
        int i,j; cin>>i>>j;
        g[i][j]++,g[j][i]++;
        d[i]++,d[j]++;
    }
    // cout<<1<<endl;
    int start=1;
    while(!d[start]) start++;
    for(int i=1;i<=n;i++){
        if(d[i]%2){
            start=i;
            break;
        }
    }
    dfs(start);
    for(int i=cnt;i>=1;i--){
        cout<<ans[i]<<endl;
    }

    return 0;
}