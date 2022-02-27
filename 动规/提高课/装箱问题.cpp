#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=2e4+10;
int v[maxn],dp[maxn];
int n,V;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>V>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=V;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
    }

    cout<<V-dp[V];

    return 0;
}
