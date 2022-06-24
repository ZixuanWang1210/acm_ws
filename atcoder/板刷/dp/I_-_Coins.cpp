#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

const int maxn=3100;
double dp[maxn][maxn];
double p[maxn];
int n;

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]+=dp[i-1][j]*(1-p[i]);
            dp[i][j+1]+=dp[i-1][j]*p[i];
        }
    }

    double res=0;
    for(int i=(n+1)/2;i<=n;i++){
        res+=dp[n][i];
    }
    cout<<fixed<<setprecision(11)<<res<<endl;

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
