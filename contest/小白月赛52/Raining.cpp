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
    int a,b,c,d; cin>>a>>b>>c>>d;
    int x; cin>>x;
    cout<<max(0,x-a)<<' ';
    cout<<max(0,x-b)<<' ';
    cout<<max(0,x-c)<<' ';
    cout<<max(0,x-d)<<' ';

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
