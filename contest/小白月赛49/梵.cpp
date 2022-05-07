#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;
#define int long long
int a,b;
const int mod=998244353;
const int v6=(mod+1)/6;
const int v2=(mod+1)/2;

int get(int n){

    int t=(n*(n+1))%mod;
    t=(t*(2*n+1)%mod)%mod;
    t*=v6;
    t%=mod;

    // int tt=(a+b)%mod;
    // tt=tt+(a+b)*n%mod;
    // tt%=mod;
    // tt=tt*v2%mod;
    int tt=(a+b)*(n+1)%mod*n%mod*v2%mod;

//     int ttt=a*b%mod;
//     ttt*=n;
//     ttt%=mod;
    int ttt=a*b%mod*n%mod;

    int ans=-t+tt-ttt;
    ans=(ans%mod+mod)%mod;
    return ans;
    // return (-(n%mod*(n+1)%mod*(2*n%mod+1)%mod/6)+(((a+b+(a+b)%mod*n%mod)%mod*n)%mod/2)-a%mod*b%mod*n%mod);
    // return (-(n*(n+1)*(2*n+1)/6)+((a+b+(a+b)*n)*n/2)-a*b*n);
}

void sol(){
    cin>>a>>b; 
    // cout<<get(1)<<endl;
    // cout<<get(1)<<' '<<get(4)<<endl;
    cout<<(get(b)-get(a)+mod)%mod<<endl;


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
