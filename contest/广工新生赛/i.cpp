#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

long long get(int x){
    if(x < 2) return x;
    long long ans = 0;
    for(int i = 2; i <= x / i; i ++){
        int cnt = 0;
        while(x % i == 0){
            x /= i;
            ans ++;
        }
    }
    if(x > 1) ans ++;
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    int n; cin >> n;
    cout << get(n);

    return 0;
}
