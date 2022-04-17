#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1e6+10;
unsigned long long dp[maxn],s[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    dp[1]=dp[2]=1;
    s[1]=1,s[2]=2;
    for(int i=3;i<=18-8;i++){
        dp[i]=dp[i-1]+dp[i-2]+1;
        // cout<<dp[i]<<" ";
        dp[i]%=114514919810;
        s[i]=s[i-1]+dp[i];
        // cout<<s[i]<<endl;
        s[i]%=114514919810;
    }
    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        cout<<s[x]<<endl;
    }

    return 0;
}
