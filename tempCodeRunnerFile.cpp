#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

int t, n;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        int a, b, target; cin >> a >> b >> target;
        if(a > b) swap(a, b);
        int cnt = 0;
        if((a + b) & 1){
            cout << "-1" << endl;
            continue;
        }
        while(target > b){
            target /= 2;
            cnt ++;
        }
        if(target == a || target == b) cout << cnt << endl;
        else if(target < b && target > a) cout << cnt + 1 << endl;
        else if(target < a) cout << cnt + 1 << endl;
    }

    return 0;
}
