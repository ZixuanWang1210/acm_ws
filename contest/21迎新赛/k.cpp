#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int C = 1e9 + 7;

ll p, k;

ll qmi(int a, int b, int p){
    ll res = 1 % p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * (ll)a % p;
        b >>= 1;
    }
    return res;
}

ll phi(int x){
    int res = x;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);

    return res;
}

int main(){
    cin >> p >> k;
    ll tmp = (qmi(p, k - 1, (C)) * phi(p) % (C)) % (C);
    cout << tmp;

    return 0;
}