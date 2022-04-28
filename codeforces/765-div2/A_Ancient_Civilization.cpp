#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    int ttt; cin>>ttt;
    vector<int> v(n+1);
    vector<int> cnt(ttt+2);
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        int idx=0;
        while(x){
            if(x&1) cnt[idx]++;
            x>>=1;
            idx++;
        }
    }
    int ans=0;
    for(int i=0;i<cnt.size();i++){
        int x1=cnt[i],x2=n-cnt[i];
        if(x1>x2) ans+=(1<<i);
    }
    cout<<ans<<endl;
    // int tt=*max_element(cnt.begin(),cnt.end());
    // int ans=0;
    // for(int i=0;i<cnt.size();i++){
    //     if(cnt[i]==tt){
    //         ans+=(1<<i);
    //     }
    // }
    // cout<<ans<<endl;
}

// void sol(){
//     int n,xxx; cin>>n>>xxx;
//     vector<int> v(n+1);
//     int res=0;
//     for(int i=1;i<=n;i++) {
//         cin>>v[i];
//         if(res==0) res=v[i];
//         else res^=v[i];
//     }
//     cout<<res<<endl;
// }

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
