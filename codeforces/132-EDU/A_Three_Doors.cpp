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
    int k; cin>>k;
    int b[4];
    bool vis[4]={false};
    for(int i=1;i<=3;i++) cin>>b[i];

    if(b[k]==0||b[b[k]]==0){
        cout<<"NO"<<endl;
        return;
    }    
    cout<<"YES"<<endl;
    return;
    // vis[k]=true;
    // while(!vis[k]){
    //     vis[k]=true;
    //     k=b[k];
    // }
    // for(int i=1;i<=3;i++){
    //     if(!vis[i]){
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }
    // cout<<"YES"<<endl;

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
