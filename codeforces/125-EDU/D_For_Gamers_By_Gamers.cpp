#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
#define int long long
// typedef unsigned long long ull;

using namespace std;

const int manx=1e6+10;
int C,n,m;
int dp[manx];

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>C;
    for(int i=1;i<=n;i++){
        int d,c,h; cin>>c>>d>>h;
        dp[c]=max(dp[c],d*h);
    }

    for(int i=1;i<=C;i++){
        for(int j=i;j<=C;j+=i){
            dp[j]=max(dp[j],(j/i)*dp[i]);
        }
    }

    for(int i=1;i<=C;i++){
        dp[i]=max(dp[i-1],dp[i]);
    }

    cin>>m;
    
    while(m--){
        int d,h; cin>>d>>h;
        int idx=upper_bound(dp+1,dp+1+C,d*h)-dp;
        if(idx>C){
            cout<<-1<<' ';
            // return ;
        }
        else cout<<idx<<' ';
    }
    

    return 0;
}
