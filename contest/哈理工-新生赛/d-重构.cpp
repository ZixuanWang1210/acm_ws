#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n, l, r;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> l >> r;

    int _max = -1;
    for(int i = l; i <= r; i++){
        _max = max(_max, i % n);
    }   
    cout << _max;

    return 0;
}
