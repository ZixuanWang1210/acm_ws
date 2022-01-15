//基于分解质因数表
#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    while(n--){
        int x; cin >> x;
        int ans = x;
        for(int i = 2; i <= x / i; i++){
            if(x % i == 0){
                ans = ans / i * (i - 1);
                while(x % i == 0){
                    x /= i;
                }
            }
        }
        if(x > 1) ans = ans / x * (x - 1);
        cout << ans << endl;
    }
    

    return 0;
}
