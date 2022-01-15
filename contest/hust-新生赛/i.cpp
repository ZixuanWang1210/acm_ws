#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int a, b;
ll ans;
// bool st[10] = {false};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int n; cin >> n;
    for(int i = 1; i * i <= n; i++){
        int shu = i * i;
        for(int j = 1; shu * j <= n; j++){
            if(shu * j <= n ){
                ans ++;
                // st[shu * j] = true;
            }
        }
        // cout << ans << endl;
    }
    
    cout << ans;

    return 0;
}
