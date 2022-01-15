#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e6 + 10;
ll a[maxn], s[maxn], c[maxn];
int n, ans;
ll sum;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    ll avg = s[n] / n;

    for(int i = 1; i <= n; i++){
        c[i - 1] = i * avg - s[i];
    }


    nth_element(c, c + n / 2, c + n);
    ll res = 0;
    for(int i = 0; i < n; i++){
        res += abs(c[i] - c[n / 2]);
    }
    
    cout << res;
    return 0;
}
