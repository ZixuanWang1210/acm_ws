#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    int mp[2000][2000];
    bool vis[2000][2000]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i-1][j]==0){
                ans^=mp[i][j];
                vis[i][j-1]^=1;
                vis[i][j+1]^=1;
                vis[i+1][j]^=1;
                vis[i-1][j]^=1;
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) sol();

    return 0;
}
