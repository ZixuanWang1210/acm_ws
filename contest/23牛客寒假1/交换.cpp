#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

int dp[600][600][3];
int n;
string s;

void sol(){
    cin>>n>>s;
    memset(dp,0x7f,sizeof dp);

    vector<int> pos;
    pos.push_back(-1);
    for(int i=0;i<s.length();i++){
        if(s[i]=='1') pos.push_back(i+1);
    }
    int cnt=pos.size()-1;

    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]);
            dp[i][j][1]=dp[i-1][j-1][0]+abs(pos[j]-i);

        }
    }
    int ans=min(dp[n][cnt][0],dp[n][cnt][1]);
    if(ans>n*n) ans=-1;
    cout<<ans<<endl;
    return;

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
