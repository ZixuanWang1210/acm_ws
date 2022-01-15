#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// typedef unsigned long long ull;
const int maxn = 1e9 + 10;
using namespace std;

ll n, ans;
unordered_set<int> s;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    int re_max = 0, re_min = 0;
    int now_max, now_min;
    while(n--){
        int a, b; cin >> a >> b;
        now_max = max(a, b), now_min = min(a, b);

        for(ll i = re_max; i <= now_min; i++){
            if(i == b && i == b) continue;
            ans ++;
        }

        re_max = now_max, re_min = now_min;

    }
    
    cout << ans;
    return 0;
}
