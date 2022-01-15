#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;
const int maxn = 1e5 + 10;
// const int maxn = 10;
using namespace std;

int n, q, x;
int mx[maxn], mn[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> q;
    mx[0] = -1, mn[0] = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++){
        int temp = 0; cin >> temp;
        mx[i] = max(mx[i - 1], temp);
        mn[i] = min(mn[i - 1], temp);
    }

    while(q--){
        cin >> x;
        cout << mx[x] - mn[x] << " ";
    }
    

    return 0;
}
