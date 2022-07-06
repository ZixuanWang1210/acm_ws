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


// void sol(){
//     int k,x; cin>>k>>x;
//     int sum=(1+k)*k/2;
//     if(sum+(1+k-1)*(k-1)/2<=x){
//         cout<<2*k-1<<endl;
//         return;
//     }
//     int res=0;
//     if(x>sum) x-=sum,res+=k;
//     res+=ceil((double)(sqrt(1+8*x)-1)/2);
//     cout<<res<<endl;
// }

void sol(){
    int k,x; cin>>k>>x;
    int l=1,r=k;
    while(l<=r){
        int mid=(l+r)>>1;
        if(mid*(mid+1)<2*x) l=mid+1;
        else r=mid-1;
    }
    if(l<=k){
        cout<<l<<endl;
        return;
    }
    x-=k*(1+k)/2;
    l=0,r=k-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if((2*k-1-mid)*mid<2*x) l=mid+1;
        else r=mid-1;
    }
    cout<<min(k+l,2*k-1)<<endl;
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
