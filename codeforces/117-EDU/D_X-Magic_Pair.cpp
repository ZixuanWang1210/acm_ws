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
    int a,b,x; cin>>a>>b>>x;
    if(b>a) swap(a,b);
    // if(a<x||b<x){
    //     cout<<"NO"<<endl;
    //     return;
    // }
    while(b){
        if(x%b==a%b&&x<=a){
            cout<<"YES"<<endl;
            return;
        }
        // a-=b;
        a%=b;
        if(b>a) swap(a,b);
    }
    cout<<"NO"<<endl;
    return;

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
