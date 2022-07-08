#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    int a[n+1]={0};
    for(int i=0;i<n;i++) cin>>a[i],a[i]--;

    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;
    
    for(int i=0;i<n;i++){
        if(dp[i]==-1) continue;
        vector<int> cnt(n+1);
        int mx=0;
        for(int j=i;j<=n;j++){
            if(j>i){
                mx=max(mx,++cnt[a[j-1]]);
            }
            if((j-i)%2==0&&mx*2<=j-i){
                if(j==n){
                    dp[n]=max(dp[n],dp[i]);
                }
                else if(i==0||a[i-1]==a[j]){
                    dp[j+1]=max(dp[j+1],dp[i]+1);
                }
            }
        }
    }
    cout<<dp[n]<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
