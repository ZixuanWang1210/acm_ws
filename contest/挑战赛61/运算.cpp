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

void sol(){
    int n; cin>>n;
    vector<int> v(n+2);
    int ans=0;
    for(int i=1;i<=n+1;i++){
        cin>>v[i];
        if(v[i]>0){
            ans=max({ans,ans+v[i],ans|v[i]});
        }
        if(v[i]<0){
            ans=max({ans,ans-v[i],ans|v[i]});
        }
    }
    cout<<ans<<endl;

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
