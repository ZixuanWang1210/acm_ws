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
    int n,k; cin>>n>>k;
    vector<int> v(n+1),vv(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    if(k==1){
        cout<<(n-1)/2<<endl;
        return;
    }
    int ans=0;
    for(int i=2;i<n;i++){
        if(v[i]>v[i-1]+v[i+1]) ans++;
    }
    // for(int i=1;i<=n;i++){
        cout<<ans<<endl;
    //     vv[i]=v[i]-v[i-1];
    // }
    // int cnt=0;
    // for(int i=1;i<=n;i++){
    //     if(v[i]>0&&v[i+1]<0) cnt++;

    // }

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
