#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define debug_(ch, i) printf(#ch"[%d]: %d\n", i, ch[i])
#define debug_m(mp, p) printf(#mp"[%d]: %d\n", p->first, p->second)
using namespace std;

int qPow(int a, int b){
    int ans = 1, base = a;
    while(b > 0){
        if(b & 1) ans *= base;
        base *= base, b >>= 1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cout << qPow(2, 10);

    return 0;
}
