#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int l1,l2,r1,r2;
    cin>>l1>>r1>>l2>>r2;
    if(l2>=l1&&l2<=r1){
        cout<<l2<<endl;
        return;
    }
    if(l1>=l2&&l1<=r2){
        cout<<l1<<endl;
    }
    else{
        // if(l2>l1){
        //     cout<<l2+r1<<endl;
        //     return;
        // }
        // else{
        //     cout<<l1+r2<<endl;
        //     return;
        // }
        cout<<min(l1+l2,r1+r2)<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
