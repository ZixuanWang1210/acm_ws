#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1e6;
int dp[maxn];
int a[maxn];
int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    // dp[2]=a[2];
    memset(dp,0x3f,sizeof dp);
    dp[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            dp[i]=dp[j]+(i-j)*(i-j)*(i-j)*a[j];
            cout<<i<<" "<<dp[i]<<endl;
        }
    }
    cout<<dp[n];

    return 0;
}
