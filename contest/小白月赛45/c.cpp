#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<ll,ll>
#define int long long 
using namespace std;

pii get(int x){
    ll cnt1=x/4;
    x%=4;
    
    ll cnt2=x/3;
    x%=3;

    return {cnt1,cnt2};
}
ll ans=0;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll a[10];
    for(int i=1;i<=8;i++) cin>>a[i];
    for(int i=1;i<=8;i++){
        auto cc=get(a[i]);

        a[i+1]+=cc.first+cc.second;
        ans+=(cc.first*4*i+cc.second*3*i);
    }
    cout<<ans<<endl;

    return 0;
}
