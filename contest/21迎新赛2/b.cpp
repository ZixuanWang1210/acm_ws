#include <bits/stdc++.h>
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

ll jiecheng(int x){
    ll ans = 0;
    for(int i = 1; i <= x; i++){
        ans *= i;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    int t; cin >> t;
    ll sum = 0;
    while(t--){
        int a, b;
        cin >> a >> b;
        int base = jiecheng(b);
        for(int i = b; i != a + 1; i++){
            sum += base;
            base *= i;
        }
    }
    cout << sum;



    return 0;
}
