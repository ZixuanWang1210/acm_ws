#include <bits/stdc++.h>
#define endl "\n"

typedef unsigned long long ull;
#define P 998244353
using namespace std;

// int a[1000000010];
int n;
int ans;

ull fu(int x, int n){
    return (x + (n/x)*x)*(n/x)/2;
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    ull x = fu(3, n) % P;
    ull y = fu(5, n) % P;
    ull z = fu(7, n) % P;

    ull xy = fu(15, n) % P;
    ull xz = fu(21, n) % P;
    ull yz = fu(35, n) % P;
    ull xyz = fu(105, n) % P;

    // printf("%d %d %d %d\n", x, y, z, xy);
    ull ans = x + y + z - xy - xz- yz + xyz;
    cout << ans % P;
    return 0;
}
