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

const int maxn=2e5+10;
int dp[maxn][11];
int t[10];
int n,m;

void sol(){
    cin>>n>>m;
    for(int i=0;i<10;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        for(int j=0;j<10;j++){
            dp[i][j]=dp[i-1][j];
        }
        swap(dp[i][x],dp[i][y]);
    }
    while(m--){
        int x,y; cin>>x>>y;

        for(int i=0;i<10;i++){
            t[dp[x-1][i]]=i;
        }
        for(int i=0;i<10;i++){
            cout<<t[dp[y][i]]<<' ';
        }
        cout<<endl;
    }

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
