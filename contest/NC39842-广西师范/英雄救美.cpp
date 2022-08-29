#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

// const int maxn=1e5+10;
// int dp[maxn][310][3];
// int w[maxn][3];
// int c[maxn];
// int ls[maxn],rs[maxn];
// int n,k;
// int fr[maxn];

// void dfs(int u,int fa){
//     if(ls[u]){
//         fr[u]=fr[ls[u]];
//         for(int i=0;i<=k;i++){
//             dp[u][i][0]=dp[ls[u]][i][1]+c[ls[u]];
//         }
//         for(int i=1;i<=k;i++){
//             dp[u][i][0]=max(dp[u][i][0],dp[ls[u]][i-1][1]+c[rs[u]]);
//         }
//         dfs(ls[u],u);

//     }
//     else{
//         fr[u]=u;
//     }
//     if(rs[u]){
//         for(int i=1;i<=k;i++){
//             dp[u][i][1]=dp[rs[u]][i][0]+c[rs[u]];
//         }
//         for(int i=1;i<=k;i++){
//             dp[u][i][1]=max(dp[u][i][1],dp[rs[u]][i-1][0]+c[ls[u]]);
//         }
//         dfs(rs[u],u);
//     }
//     else{
//         fr[u]=u;
//     }
// }
const int N=1e5+5;
 
int n,m;
int ls[N],rs[N];
int val[N];
int mx,pos;
 
void dfs(int x,int k,int num,int f){
    if(!x||num>m)return;
     
    val[x]+=val[f];
     
    if(ls[x]+rs[x]==0){
        if(mx<val[x]){
            mx=val[x];
            pos=x;
        }else if(mx==val[x]){
            pos=min(pos,x);
        }
        return ;
    }
     
    if(k==0){
        dfs(rs[x],1,num,x);
        dfs(ls[x],1,num+1,x);
    }else if(k==1){
        dfs(rs[x],0,num+1,x);
        dfs(ls[x],0,num,x);
    }else{
        dfs(ls[x],0,num,x);
        dfs(rs[x],1,num,x);
    }
}
void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>val[i];

    for(int i=1;i<n;i++){
        int u,v,st; cin>>u>>v>>st;
        if(st==1) ls[u]=v;
        else rs[u]=v;
    }


    // int res=-1;
    pos=0,mx=0;
    dfs(1,-1,0,0);
    // for(int i=0;i<=k;i++){
    //     res=max({res,dp[1][i][0],dp[1][i][1]});
    // }
    cout<<pos<<endl;
    cout<<mx<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
