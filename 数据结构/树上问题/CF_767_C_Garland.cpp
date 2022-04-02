#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e6+10;
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
int n;
int dp[maxn];
int cost[maxn];
int dep[maxn];
int res,sum;
vector<int> ans;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    // dep[u]=dep[fa]+1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        if(cost[j]==sum){
            res++;
            ans.push_back(j);
        }
        else cost[u]+=cost[j];
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int root=0;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int v; cin>>v;
        cin>>cost[i];
        if(v==0) root=i;
        else add(i,v),add(v,i);
        sum+=cost[i];
    }
    if(sum%3){
        cout<<-1<<endl;
        return 0;
    }
    sum/=3;
    // cout<<root<<endl;

    dfs(root,0);

    if(res<2) cout<<-1<<endl;
    else cout<<ans[1]<<' '<<ans[0];
    
    return 0;
}
