#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n,m; cin>>n>>m;
    char mp[100][100];
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=m;j++){
            if(i==n+1) {
                mp[i][j]='o';
                continue;
            }
            cin>>mp[i][j];
        }
    }
    

    for(int j=1;j<=m;j++){
        int cnt=0;
        for(int i=1;i<=n+1;i++){
            if(mp[i][j]=='*'){
                mp[i][j]='.';
                cnt++;
            }
            else if(mp[i][j]=='o'){
                for(int k=1;k<=cnt;k++){
                    mp[i-k][j]='*';
                }
                cnt=0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<mp[i][j];
        }
        cout<<endl;
    }
    cout<<endl;


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
