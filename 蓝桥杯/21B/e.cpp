#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

int dp[2][10000000];
int mp[10000000];

signed main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    dp[1][1]=1;
    int len=2;
    int cnt=1;
    mp[1]=cnt;
    
    for(int i=2;i<=26;i++,len++){
        for(int j=1;j<=len;j++){
            cnt++;
            dp[i&1][j]=dp[(i&1)^1][j]+dp[(i&1)^1][j-1];
            // cout<<dp[i&1][j]<<' ';
            if(mp[dp[i&1][j]]==0){
                mp[dp[i&1][j]]=cnt;
            }
        }
    }
    int n; cin>>n;
    cout<<mp[n]<<endl;
    

    return 0;
}
