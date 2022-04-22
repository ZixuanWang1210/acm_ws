#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n,m,sx,sy,gx,gy;
    cin>>n>>m>>sx>>sy>>gx>>gy;
    int ans1=gx-sx;
    if(ans1<0) ans1=(2*n-sx-gx);
    int ans2=gy-sy;
    if(ans2<0) ans2=(2*m-sy-gy);
    cout<<min(ans1,ans2)<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
