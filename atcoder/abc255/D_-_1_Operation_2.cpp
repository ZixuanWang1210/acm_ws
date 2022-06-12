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
    int n,q; cin>>n>>q;
    vector<int> v(n+1),s(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        // s[i]=s[i-1]+v[i];
    }
    sort(all(v));
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+v[i];
    }


    while(q--){
        int x; cin>>x;
        int idx1=lower_bound(all(v),x+1)-v.begin();
        int idx2=lower_bound(all(v),x)-v.begin()-1;
        // cout<<idx1<<' '<<idx2<<endl;
        // cout<<(s[n]-s[idx1-1])-x*(n-idx1+1)<<endl;
        cout<<(s[n]-s[idx1-1])-x*(n-idx1+1) + x*idx2-s[idx2]<<endl;
    }
}
// void sol(){
//     int n,q; cin>>n>>q;
//     vector<int> v(n+1);
//     int sum=0;
//     for(int i=1;i<=n;i++){
//         cin>>v[i];
//     }
//     sort(all(v));

//     while(q--){
//         int x; cin>>x;
//     }
// }

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
