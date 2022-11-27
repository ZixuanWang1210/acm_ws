#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

void sol(){
    ll a,b,d;cin>>a>>b>>d;
    ll x_=__builtin_ctzll(d),y_=min(__builtin_ctzll(b),__builtin_ctzll(a));
    if(x_>y_){cout<<-1<<'\n';return;}
    else{
        ll nd=(a|b);
        ll nw=0;
        for(int i=0;i<30;i++)
            if((nw>>i&1)!=(nd>>i&1)){
                nw+=d<<(i-x_);
            }
        cout<<nw<<endl;;
    }

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
