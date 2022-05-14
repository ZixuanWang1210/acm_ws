#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n,m;
    cin>>n>>m;
    char mp[10][10]={'.'};
    int x,y;
    int dis=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='R'){
                if(dis>i+j) dis=i+j,x=i,y=j;
            }
        }
    }
    // cout<<x<<' '<<y<<endl;
    // cout<<dis<<endl;
    for(int i=1;i<x;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='R'){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<y;j++){
            if(mp[i][j]=='R'){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
