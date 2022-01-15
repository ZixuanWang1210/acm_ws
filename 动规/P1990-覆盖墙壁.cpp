#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int ans, n;
int f[maxn];

int main(){
    cin >> n;

    f[1] = 1;
    f[2] = 2;
    f[3] = 5;
    for(int i = 4; i <= n; i++){
        f[i] = (2 * f[i - 1]) % 10000 + f[i - 3] % 10000;
        f[i] %= 10000;
    }
    cout << f[n];

    return 0;
}