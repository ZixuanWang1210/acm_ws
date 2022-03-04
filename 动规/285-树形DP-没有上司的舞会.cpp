#include<bits/stdc++.h>
using namespace std;

const int maxn=6100+10;
int h[maxn],ne[maxn],e[maxn],idx;
int n;
int happy[6100];
int dp[6100][2];
bool have_fa[6100];
int root;

void dfs(int u){
    dp[u][1]=happy[u];
    // cout<<dp[u][1]<<endl;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        dfs(j);
        dp[u][1]+=dp[j][0];
        dp[u][0]+=max(dp[j][0],dp[j][1]);
        // cout<<dp[u][0]<<' '<<dp[u][1]<<endl;
    }
}

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>happy[i];
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int a,b; cin>>a>>b;
        add(b,a);
        have_fa[a]=true;
    }
    for(int i=1;i<=n;i++){
        if(!have_fa[i]){
            root=i;
            // cout<<root;
            break;
        }
    }
    // cout<<"root"<<root<<endl;
    dfs(root);
    cout<<max(dp[root][0],dp[root][1])<<endl;

    return 0;
}