#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

int n,m;
const int maxn=1e5+10;
int dp[maxn];
int c[maxn];

void sol(){
    int res=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=c[i];j--){
            dp[j]+=dp[j-c[i]];
        }
    }
    cout<<dp[m]<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
