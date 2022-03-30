#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int unsigned long long
using namespace std;

void sol(){
    int n,fx,x0;
    cin>>n>>fx>>x0;
    cout<<(fx*n+(n+1)*x0)/(n+1)<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
