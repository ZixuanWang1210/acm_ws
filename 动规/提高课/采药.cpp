#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=2000;
int n,m;
int dp[maxn];
int w[maxn],v[maxn];


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>w[i]>>v[i];

    for(int i=1;i<=m;i++){
        for(int j=n;j>=w[i];j--){
            // dp[i][j]=dp[i-1][j];
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[n];
    
    return 0;
}
