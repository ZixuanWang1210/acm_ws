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
    int n,k; cin>>n>>k;
    map<char,double> mp;
    mp['D']=16;mp['C']=24;mp['B']=54;mp['A']=80;mp['S']=10000;

    double res=0;
    while(n--){
        char x; cin>>x;
        double t; cin>>t;
        res+=(mp[x]-23)*t;
    }
    cout<<fixed<<setprecision(12)<<res*k<<endl;


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
