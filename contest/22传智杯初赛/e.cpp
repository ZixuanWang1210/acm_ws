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
    int q; cin>>q;
    int x; 
    auto check=[&](int mid){
        int t=mid+mid*(mid-1)*4/2;
        if(t<=x) return true;
        else return false;
    };
    while(q--){
        cin>>x;
        int l=1,r=2e9;
        while(l<r){
            int mid=l+r+1>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        int t=l+l*(l-1)*4/2;
        x-=t;
        l++;
        if(!x) cout<<0<<endl;
        else if(x<=l) cout<<x-1<<endl;
        else if(x>1&&x<=2*l+l-2) cout<<(l-1)-(x-l)<<endl;
        else cout<<-((l-1)-(x-2*l-l+2))<<endl;
    }
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
