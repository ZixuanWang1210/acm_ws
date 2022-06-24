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
    int n,k; cin>>n>>k;
    int ans=n*k;
    for(int l=1,r=0;l<=n;l=r+1){
        if(k/l) r=min(k/(k/l),n);
        else r=n;
        ans-=(k/l)*(r-l+1)*(l+r)/2;
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
