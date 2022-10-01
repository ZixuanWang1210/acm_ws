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

// void sol(){
//     int n; cin>>n;
//     vector<int> v(n+1);
//     for(int i=1;i<=n;i++){
//          cin>>v[i];
//     }
//     int res=0;
//     for(int i=1;i<=n;i++){
//         int x; cin>>x;
//         res+=x;
//     }
//     sort(all(v));
//     double mid;
//     if(n&1){
//         mid=v[(1+n)/2];
//     }
//     else{
//         mid=(v[floor((double)(1+n)/2)]+v[ceil((double)(1+n)/2)])/2;
//     }
//     for(int i=1;i<=n;i++){
//         res+=abs(v[i]-mid);
//     }
//     cout<<res<<endl;
// }

void sol(){
    int n; cin>>n;
    vector<int> v(n+1),t(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    double a=0,b=1e9;
    for(int i=1;i<=n;i++){
        a=max(a,0.0+v[i]+t[i]);
        b=min(b,0.0+v[i]-t[i]);
    }
    cout<<fixed<<setprecision(7)<<(a+b)/2<<endl;
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
