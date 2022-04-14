#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

const int maxn=15000;
int dp[maxn][2];
// int h[maxn],ne[maxn],e[maxn],idx;
int n,m;

// void add(int a,int b){
//     e[idx]=b,ne[idx]=h[a],h[a]=idx++;
// }
struct graph {
    vector<int> e, h, w, ne;
    int n, idx;
    graph(int n) : e(2 * n + 1), h(n + 1), w(2 * n + 1), ne(2 * n + 1) {
        for (int i = 0; i < 2 * n + 1; i++) {
            e[i] = w[i] = ne[i] = 0;
            if (i <= n) h[i] = -1;
        }
    }
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void add(int a, int b, int c) {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }
};

graph g(1500);
void dfs(int u,int fa){
    dp[u][0]=0,dp[u][1]=1;
    for(int i=g.h[u];~i;i=g.ne[i]){
        int j=g.e[i];
        if(j==fa) continue;
        dfs(j,u);
        dp[u][0]+=dp[j][1];
        dp[u][1]+=min(dp[j][0],dp[j][1]);
    }
}

int main(){
    // while(cin>>n){
        cin>>n;
        // for(int i=0;i<4*n;i++){
        //     g.h[i]=-1,g.e[i]=ne[i]=0;
        //     dp[i][0]=dp[i][1]=0;
        // }
        // g.idx=0;
        for(int i=1;i<=n;i++){
            int a,b,siz;
            // scanf("%d:(%d) ", &a, &siz);
            cin>>a>>siz;
            while(siz--){
                cin>>b;
                g.add(a,b),g.add(b,a);
            }
        }
        dfs(1,-1);
        cout<<min(dp[1][0],dp[1][1])<<endl;
    // }

    return 0;
}
