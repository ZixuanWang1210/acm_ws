#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int maxn = 1e5 + 10;
const int maxn = 10;

int n;
ll sum;
int a[maxn], g[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    sort(a, a + n + 1);
    for(int i = 1; i <= n; i++) g[i] = a[i] - a[i - 1];

    int re = 0, ans = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++){
        if(re == a[i]) continue;
        int sum = 0, su = 0;
        for(int j = i + 1; j <= n; j++){
            su += g[j];
            sum += su;
        }
        su = 0;
        for(int j = i; j > 1; j--){
            su += g[j];
            sum += su;
        }
        ans = min(ans, sum);

        re = a[i];
    }
    cout << ans * 2;
    return 0;
}
