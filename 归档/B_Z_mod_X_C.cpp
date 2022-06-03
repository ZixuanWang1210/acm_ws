#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    vector<int> v(4);
    cin>>v[1]>>v[2]>>v[3];
    cout<<v[1]<<' '<<v[1]+v[2]+v[3]<<' '<<v[1]+v[2]<<endl;


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
