#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int dp[1010];
int n; 
const int N=1e9+7;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[j]=(dp[j]+dp[j-i])%N;
        }
    }
    cout<<dp[n]<<endl;

    return 0;
}
