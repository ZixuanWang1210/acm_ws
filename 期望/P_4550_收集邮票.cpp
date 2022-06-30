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
    double dp[n+1],g[n+1];
    for(int i=n-1;i>=0;i--){
        dp[i]=dp[i+1]+(1.0*n)/(1.0*(n-i));
        g[i]=(1.0*i)/(1.0*(n-i))*(dp[i]+1)+g[i+1]+dp[i+1]+1;
    }    
    cout<<fixed<<setprecision(2)<<g[0]<<endl;

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
