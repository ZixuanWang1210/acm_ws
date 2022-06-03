#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;
const int maxn=500;
int dp[maxn][maxn];
int dp1[maxn][maxn];
int s[maxn];

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i+n]=s[i];
    }

    for(int i=1;i<=2*n;i++){
        s[i]+=s[i-1];
    }

    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=2*n;l++){
            int r=l+len-1;
            dp[l][r]=1e8;
            for(int k=l;k<r;k++){
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+s[r]-s[l-1]);
                dp1[l][r]=max(dp1[l][r],dp1[l][k]+dp1[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        ans=min(ans,dp[i][i+n-1]);
    }
    int ans1=0;
    for(int i=1;i<=n;i++){
        ans1=max(ans1,dp1[i][i+n-1]);
    }

    cout<<ans<<endl;
    cout<<ans1<<endl;
    return ;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

        sol();

    return 0;
}
