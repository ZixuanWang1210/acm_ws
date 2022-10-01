#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
// #define ll long long
#define int long long
#define ll long long

using namespace std;

void sol(){
    ll l=1,r=1e18+10;
    int ans=0;
    auto check=[&](int mid){
        // cout<<"? "<<l<<" "<<mid<<endl;
        printf("? %lld %lld",1,mid);
        fflush(stdout);
        int x; cin>>x;
        if(x==-1) return false;
        else return true;
    };
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) l=mid+1,ans=l;
        else r=mid-1;
    }
    // cout<<ans<<endl;
    printf("! %lld",ans-1);
    fflush(stdout);

}

signed main(){

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
