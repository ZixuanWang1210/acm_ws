#include <bits/stdc++.h>
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

ll k, m, n;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> k >> m >> n;
    vector<ll> v;
    for(int i = 1; i <= m; i++){
        ll a, b;
        cin >> a >> b;

        ll h = k / a * b;
        if(h >= n) v.push_back(i);
    }
    
    if(v.empty()){
        cout << -1;
        return 0;
    }

    for(auto x : v){
        cout << x << " ";
    }

    return 0;
}
