#include <bits/stdc++.h>
#define endl "\n"
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n, k;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> k;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int x = i;
        while(x){
            int temp = x % 10;
            if(temp == k){
                cnt ++;
                cout << i << endl;
            }
            x /= 10;
        }
    }
    cout << cnt;

    return 0;
}
