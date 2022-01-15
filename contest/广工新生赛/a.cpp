#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

ll a, b;
const ll P = 999068070;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> a >> b;
    ll j_a = 0, j_b = 0;
    bool biga = b > a;
    ll temp = 1;
    for(int i = 1; i <= max(a, b); i++){
        if(i == min(a, b)) biga ? j_b = temp : j_a = temp;
        if(i == max(a, b)) !biga ? j_b = temp : j_a = temp;
        temp = temp * (i % P);
    }

    if(j_b > j_a) puts("b is the winner!");
    else puts("a is the winner!");

    return 0;
}
