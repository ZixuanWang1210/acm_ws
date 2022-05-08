#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

const int maxn=5e5+10;
int dp[maxn];

int get(int x){
    return lower_bound(dp+1,dp+40000+1,x)-dp;
}

void sol(){
    int n; cin>>n;
    cout<<get(n)<<endl;

}
int cnt[3]={1,1,1};

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    dp[2]=2,dp[3]=6;

    for(int i=4;i<=40000;i++){
        int t=i%3;
        dp[i]=dp[i-1];
        for(int j=0;j<3;j++){
            if(j!=t) dp[i]+=2*cnt[j];
        }
        cnt[t]++;
    }


    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
