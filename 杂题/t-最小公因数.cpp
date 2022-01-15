#include <bits/stdc++.h>
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

// ll get_divisors(int x){
//     vector<int> res;
//     for (int i = 1; i <= x / i; i ++ )
//         if (x % i == 0){
//             res.push_back(i);
//             if (i != x / i) res.push_back(x / i);
//         }

//     ll num = 1;
//     for(auto x: res){
//         num *= x;
//     }
//     return num;
// }

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    int a, b; cin >> a >> b;

    cout << a * b / __gcd(a, b);
    

    return 0;
}
