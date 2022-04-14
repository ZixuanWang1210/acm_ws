//与没有上司的舞会对应
#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=15000;
int dp[maxn][2];
int h[maxn],ne[maxn],e[maxn],idx;
int n,m;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    dp[u][0]=0,dp[u][1]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        dp[u][0]+=dp[j][1];
        dp[u][1]+=min(dp[j][0],dp[j][1]);
    }
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // int n;
    while(cin>>n){
        for(int i=0;i<4*n;i++){
            h[i]=-1,e[i]=ne[i]=0;
            dp[i][0]=dp[i][1]=0;
        }
        idx=0;
        for(int i=1;i<=n;i++){
            int a,b,siz;
            scanf("%d:(%d) ", &a, &siz);
            while(siz--){
                cin>>b;
                add(a,b),add(b,a);
            }
        }
        dfs(1,-1);
        cout<<min(dp[1][0],dp[1][1])<<endl;
    }

    return 0;
}
