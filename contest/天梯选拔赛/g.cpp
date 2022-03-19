#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int l,r,k; cin>>l>>r>>k;

    int now=k;
    k=1;
    int cnt=0;
    bool bz=false;
    while(k<=r){
        if(k>=l&&k<=r){
            bz=true;
            cout<<k<<' ';
        }
        cnt++;
        k=k*now;
    }
    if(!bz) cout<<"-1";

    return 0;
}
