#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=1e6+10;
int dp[maxn],v[maxn],w[maxn];
int n,m,H;

// void sol(){
//     int H; cin>>n>>H;
//     memset(dp,0x3f,sizeof dp);

//     for(int i=1;i<=n;i++){
//         cin>>v[i]>>w[i];
//     }    
//     for(int i=1;i<=n;i++){
//         for(int j=v[i];j<=H+5000;j++){
//             dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
//         }
//     }
//     int ans=0x3f3f3f3f;
//     for(int i=H;i<=H+5000;i++){
//         // ans=min(ans,dp[i]);
//         cout<<dp[i]<<' ';
//     }
//     cout<<ans<<endl;

// }

void sol(){
    int ans=0x3f3f3f3f;
    cin >> n >> H;
    for (int i = 1; i <= H + 5000; ++i){
        dp[i] = ans;//初始化 dp 数组
    }
    for (int i = 1; i <= n; ++i) {
    	cin >> v[i] >> w[i];
	}
    for (int i = 1; i <= n; ++i) {
    	for (int j = v[i]; j <= H + 5000; ++j) { //注意循环条件
    		dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
		}
	}
    for (int i = H; i <= H + 5000; ++i) {
    	ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    // return 0;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
