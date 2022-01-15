#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
const int maxn = 1e6;
using namespace std;

int a[maxn], n, m;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a, a + n + 1);
    while(m--){
        int x; cin >> x;
        int idx = a - upper_bound(a, a + n + 1, x);
        
    }
    

    return 0;
}
