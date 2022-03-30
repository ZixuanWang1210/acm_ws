#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=2000;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int dp[maxn][maxn];
int n,m;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int ver=e[i];
        if(ver==fa) continue;
        dfs(ver,u);
        for(int j=m;j>=1;j--){
            // for(int k=m-1;k>=0;k--){
            for(int k=0;k<j;k++){
                dp[u][j]=max(dp[u][j],dp[ver][k]+dp[u][j-k]);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    m++;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int s,k; cin>>s>>k;
        dp[i][1]=k;
        if(k==0) add(0,s,k),add(s,0,k);
        else add(s,i,k),add(i,s,k);
    }

    dfs(0,-1);
    
    cout<<dp[0][m];
    return 0;
}
