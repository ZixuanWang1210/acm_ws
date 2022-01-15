#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n"
// typedef unsigned long long ull;

using namespace std;

ll qmi(int a, int b, int p){
    ll res = 1 % p;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * (ll)a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int a, b, p;
    cin >> a >> b >> p;
    cout << qmi(a, b, p) << endl;

    

    return 0;
}
