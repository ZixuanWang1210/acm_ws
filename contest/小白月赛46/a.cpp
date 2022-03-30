#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;



signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    if(n&1){
        cout<<n/2<<' '<<(n+1)/2<<endl;
    }
    else{
        cout<<n/2<<endl;
    }

    return 0;
}
