#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
#define int long long
using namespace std;

ll n,m;
const ll P=100000007;
ll ans=1;


signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;

    ll M=m;
    int cnt = 0;
    while(m){
        int num = m & 1;
        if(num == 1) cnt ++;
        m >>= 1;
    }
    // int cnt;cin>>n>>cnt;
    for(int i=1;i<=cnt;i++){
        ans=((n%P)*ans)%P;
    }
    cout<<ans%P;
    return 0;
}
