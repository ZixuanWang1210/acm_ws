#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    int st,ed; cin>>st>>ed;
    double ans=0;
    int cnt=1;
    for(int i=1;i<=n+1;i++){
        int l,r; cin>>l>>r;
        if(i==1) continue;
        if(st<l){
            ans+=sqrt((l-st)*(l-st)+cnt*cnt);
            cnt=0;
            st=l;
        }
        else if(st>r){
            ans+=sqrt((r-st)*(r-st)+cnt*cnt);
            cnt=0;
            st=r;
        }
        else if(i==n+1){
            ans+=sqrt((ed-st)*(ed-st)+cnt*cnt);
        }
        cnt++;
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
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
