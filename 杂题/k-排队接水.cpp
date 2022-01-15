#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;
const int maxn = 1e3 + 10;
using namespace std;
typedef pair<int, int> pii;

int n;
pii a[maxn];

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a + 1, a + n + 1);

    long long sum = 0;
    for(int i = 1; i <= n; i++){
        sum = sum + a[i].first * (n - i);
    }
    
    double ans = (double)sum / (double)n;

    for(int i = 1; i <= n; i++){
        printf("%d ", a[i].second);
    }

    printf("\n%.2f", ans);

    return 0;
}
W