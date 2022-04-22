#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

int n,m;
const int maxn=1e5+10;

int w[maxn];
int dp[maxn];

void sol(){
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>w[i];

    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
        }
    }    
    cout<<m-dp[m]<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
