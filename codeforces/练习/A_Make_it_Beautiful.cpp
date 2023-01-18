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
    int n; cin>>n;
    vector<int> v(n+1);
    set<int> st;
    for(int i=1;i<=n;i++) cin>>v[i],st.insert(v[i]);
    sort(all(v),greater<int>());
    if(v[1]==v[n]){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    swap(v[1],v[n]);
    swap(v[2],v[n]);
    for(int i=1;i<=n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
    // bool ok=false;
    // for(int i=1;i<=n;i++){
    //     for(int j=i+1;j<=n;j++){
    //         if(st.count(v[i]+v[j])){
    //             cout<<"YES"<<endl;
    //             sort(all(v),greater<int>());
    //             for(int i=1;i<=n;i++){
    //                 cout<<v[i]<<' ';
    //             }
    //             cout<<endl;
    //             return;
    //         }
    //     }
    // }
    // cout<<"NO"<<endl;
    // return;

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
