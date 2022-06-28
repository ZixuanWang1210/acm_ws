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

const int maxn=210;
int dp[maxn][maxn];
int n;
int g[maxn][maxn];
struct node{
    int x,y,p;
} p[maxn];

int get(node x,node y){
    int dx=abs(x.x-y.x);
    int dy=abs(x.y-y.y);
    return dx+dy;
}

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y>>p[i].p;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            dp[i][j]=(get(p[i],p[j])+p[i].p-1)/(double)p[i].p;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],max(dp[i][k],dp[k][j]));
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int ans=1e18;
    for(int i=1;i<=n;i++){
        int now=0;
        for(int j=1;j<=n;j++){
            now=max(now,dp[i][j]);
        }
        ans=min(ans,now);
    }
    cout<<ans<<endl;
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
