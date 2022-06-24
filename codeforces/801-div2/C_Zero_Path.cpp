#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;
const int maxn=1100;
int dp1[maxn][maxn],dp2[maxn][maxn];
int mp[maxn][maxn];

void sol(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            dp1[i][j]=dp2[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1){
                dp2[i][j]=dp1[i][j]=dp1[i][j-1]+mp[i][j];
                continue;
            }
            if(j==1){
                dp2[i][j]=dp1[i][j]=dp1[i-1][j]+mp[i][j];
                continue;
            }
            dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+mp[i][j];
            dp2[i][j]=min(dp2[i-1][j],dp2[i][j-1])+mp[i][j];
        }
    }
    if((n+m)%2==0){
        cout<<"NO"<<endl;
        return;
    }
    else if(dp1[n][m]==0||dp2[n][m]==0){
        cout<<"YES"<<endl;
        return;
    }
    else if(dp1[n][m]>0&&dp2[n][m]<0){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
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
