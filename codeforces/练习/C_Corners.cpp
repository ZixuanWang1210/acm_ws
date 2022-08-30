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
const int maxn=1000;
int mp[maxn][maxn]={0};

void sol(){
    int n,m; cin>>n>>m;
    memset(mp,0,sizeof mp);
    int cnt1=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char t; cin>>t;
            mp[i][j]=t-'0';
            if(t=='1') cnt1++;
        }
    }

    if(!cnt1){
        cout<<0<<endl;
        return;
    }
    bool ok=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i+1<=n) if(mp[i][j]==0&&mp[i+1][j]==0) ok=true;
            if(j+1<=m) if(mp[i][j]==0&&mp[i][j+1]==0) ok=true;

        }
    }

    if(ok) {cout<<cnt1<<endl;return;}

    if(cnt1!=n*m){
        cout<<max(0,cnt1-1)<<endl;
    }
    else cout<<cnt1-2<<endl;
    // int ans=4;
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<m;j++){
    //         int t=mp[i][j]+mp[i][j+1]+mp[i+1][j]+mp[i+1][j+1];
    //         if(t){
    //             ans=min(ans,max(1,t-1));
    //         }
    //     }
    // }
    // cout<<cnt1-ans+1<<endl;
    


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
