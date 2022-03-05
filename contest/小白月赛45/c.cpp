#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<ll,ll>
#define int long long 
using namespace std;
int ans;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll a[10];
    for(int i=1;i<=8;i++) cin>>a[i];
    for(int i=1;i<=8;i++){
        ll num=a[i];

        if(a[i]<3) num=0;
        else if(num==5) num=4;
        a[i+1]+=(num/3ll);
        ans+=(ll)num;

    }
    cout<<ans<<endl;

    return 0;
}
