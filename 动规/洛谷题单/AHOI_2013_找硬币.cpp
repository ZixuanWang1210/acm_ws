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
const int MAXN=1e5+10;
int dp[MAXN];
int a[MAXN];
int maxn=0;
int n;
void sol(){
    cin>>n;
    memset(dp,0x3f,sizeof dp);
    dp[1]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        dp[1]+=a[i];
    }    
    for(int i=2;i<=maxn;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                int cnt=0;
                for(int k=1;k<=n;k++){
                    cnt+=a[k]/i*(i/j-1);
                }
                dp[i]=min(dp[i],dp[j]-cnt);

                int jj=j;
                j=i/j;
                cnt=0;
                for(int k=1;k<=n;k++){
                    cnt+=a[k]/i*(i/j-1);
                }
                dp[i]=min(dp[i],dp[j]-cnt);
                j=jj;
            }
        }
    }
    int ans=dp[1];
    for(int i=1;i<=maxn;i++){
        ans=min(ans,dp[i]);
        // cout<<i<<' '<<dp[i]<<endl;
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
