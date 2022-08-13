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
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) v[i]=i;

    int zhu=ceil(sqrt(n));
    int cnt=ceil((double)n/(double)zhu);
    // cout<<zhu<<' '<<cnt<<endl;
    for(int i=1;i<=n;i+=cnt){
        reverse(v.begin()+i,min(v.begin()+i+cnt,v.end()));
    }
    for(int i=1;i<=n;i++) cout<<v[i]<<' ';
    cout<<endl;
    // for(int i=1;i<=zhu;i++){
    //     for(int j=0;j<cnt;j++){
    //         cout<<i*cnt
    //     }
    // }
    // vector<int> v(n+1);
    // for(int i=1;i<=n;i++){
    //     v[i]=i;
    // }
    // if(n==3){
    //     cout << "1 3 2" << endl;
    //     return;
    // }
    // int mid=(n)/2;
    // reverse(v.begin()+1,v.begin()+1+mid);
    // if(n&1) reverse(v.begin()+mid+2,v.end());
    // else reverse(v.begin()+mid+1,v.end());
    // for(int i=1;i<=n;i++){
    //     cout<<v[i]<<' ';
    // }
    // cout<<endl;

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
