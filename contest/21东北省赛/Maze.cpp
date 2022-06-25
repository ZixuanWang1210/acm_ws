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

int dp[110][110][4][110];
int n,m;
int mp[110][110];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=0;j<s.length();j++){
            mp[i][j+1]=s[j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]=='*') continue;
            // for(int k=1;k<=4;k++){
                for(int s=1;s<=m;s++){
                    dp[i+1][j][2][s]=dp[i][j][2][s-1]+1;
                    cout<<dp[i+1][j][2][s]<<' ';
                    dp[i][j+1][4][s]=dp[i][j][4][s-1]+1;
                    dp[i-1][j][1][s]=dp[i][j][1][s-1]+1;
                    dp[i][j-1][3][s]=dp[i][j][3][s-1]+1;
                }
            // }            
        }
    }

    int ans=inf;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]=='*') continue;
            for(int k=1;k<=4;k++){
                for(int s=1;s<=m;s++){
                    ans=min(ans,dp[i][j][k][s]);
                }
            }            
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
