#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;
const int maxn =  1e6 + 10;

int a[maxn], s1[maxn], s2[maxn];
int ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s1[i] = s1[i - 1] + a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        s2[i] = s2[i - 1] + a[i];
        if(s2[i] == s1[i])   ans++;
    }
    cout << ans;

    return 0;
}
