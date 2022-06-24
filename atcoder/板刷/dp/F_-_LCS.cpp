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
int dp[maxn][maxn];
int n,m;
string s,t;

void sol(){
    cin>>s>>t;
    n=s.length(),m=t.length();
    s=' '+s,t=' '+t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s[i]==t[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    int i=n,j=m;
    stack<char> v;
    while(i>=1&&j>=1){
        if(s[i]==t[j]){
            v.push(s[i]);
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    while(v.size()){
        cout<<v.top();
        v.pop();
    }
    cout<<endl;
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
