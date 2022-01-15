#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;
const int maxn = 1e3 + 10;
using namespace std;

int n, q;
int a[maxn];
int mod[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> q;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    
    while(q--){
        int ans = -1;
        int x, len; cin >> len >> x;
        
        for(int i = 0; i < n; i++){
            int temp = a[i] % mod[len];
            if(temp == x){
                ans = a[i];
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
