#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long 
using namespace std;

const int maxn=5100;
int n,m,k;
int dp[maxn][maxn];
int s[maxn];


signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]+=s[i-1];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(i-m>=0) dp[i][j]=max(dp[i][j],dp[i-m][j-1]+s[i]-s[i-m]);
        }
    }
    
    cout<<dp[n][k];

    return 0;
}
