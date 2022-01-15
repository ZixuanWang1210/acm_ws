#include<bits/stdc++.h>
using namespace std;
const long maxn = 2e5 + 10;

long n, c, ans;
long a[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    for(int i = 0; i < n; i++){
        int tmp = a[i] + c;
        int num = (upper_bound(a, a + n, tmp) - a) - (lower_bound(a, a + n, tmp) - a);
        ans += num;
    }

    cout << ans;
    return 0;
}