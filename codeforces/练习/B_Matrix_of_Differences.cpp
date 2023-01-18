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

void sol(){
    int n; cin>>n;
    vector<vector<int>> v(n+1,vector<int> (n+1)); 
    int cnt=0;
    int l=1,r=n*n;
    int ok=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            v[i][j]=ok?l++:r--;
            ok^=1;
        }
        if((i&1)==0) reverse(all(v[i]));
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
    // for(int i=1;i<=n;i++){
    //     if(i&1){
    //         for(int j=1;j<=n;j++){
    //             if(j&1) v[i][j]=++cnt;
    //         }
    //     }
    //     else{
    //         for(int j=1;j<=n;j++){
    //             if((j&1)==0) v[i][j]=++cnt;
    //         }
    //     }
    // }
    // cnt=n*n;
    // for(int i=1;i<=n;i++){
    //     if(i&1)
    //     for(int j=1;j<=n;j++){
    //         if(v[i][j]==0) v[i][j]=cnt--;
    //         // cout<<v[i][j]<<' ';
    //     }
    //     else
    //     for(int j=n;j>=1;j--){
    //         if(v[i][j]==0) v[i][j]=cnt--;
    //         // cout<<v[i][j]<<' ';
    //     }
    //     // cout<<endl;
    // }
    // for(int i=1;i<=n;i++){
    //     // if((i&1)==0) reverse(all(v[i]));
    //     for(int j=1;j<=n;j++){
    //         cout<<v[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

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
