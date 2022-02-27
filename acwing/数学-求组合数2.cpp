//数据范围：1e6
//原理：组合数公式
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5 + 10, P = 1e9 + 7;
ll fact[maxn], infact[maxn];

ll qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}

int main() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        fact[i] = (ll)fact[i - 1] * i % P;
        infact[i] = (ll)infact[i - 1] * qmi(i, P - 2, P) % P;
    }

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << (ll)fact[a] * infact[b] % P * infact[a - b] % P << endl;
    }

    return 0;
}