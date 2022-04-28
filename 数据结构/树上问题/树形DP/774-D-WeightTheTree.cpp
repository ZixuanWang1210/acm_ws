#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int n;
const int maxn=2e5+10;
pii dp[maxn][2],sum[maxn][2];
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
bool st[maxn];
int d[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void Add(pii a,pii b){
    a.first+=b.first;
    a.second+=b.second;
}

bool cmp(pii a,pii b){
    if(a.first!=b.first) return a.first>b.first;
    else return a.second<b.second;
}

void dfs(int u,int fa){
    // if(st[u]) return;
    dp[u][1]={1,d[u]};
    dp[u][0]={0,1};
    // st[u]=true;

    int cnt=0;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        // cnt++;
        dfs(j,u);
        Add(dp[u][1],dp[j][0]);
        if(cmp(dp[j][0],dp[j][1])) Add(dp[u][0],dp[j][0]);
        else Add(dp[u][0],dp[j][1]);

        // dp[u][0]+=max(dp[j][0],dp[j][1]);
        // dp[u][1]+=dp[j][0];

    }
}

int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
        d[a]++,d[b]++;
    }

    if(n==2){
        cout<<2<<' '<<2<<endl<<1<<endl;
    }
    else{
        dfs(1,-1);
        if(cmp(dp[1][0],dp[1][1])){
            cout<<dp[1][0].first<<' '<<dp[1][0].second<<endl;
        }
        
    }



    return 0;
}