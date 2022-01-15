#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e5 + 10;
double a[maxn], b[maxn], c[maxn];

double f(int n){
    a[n] = f(n - 1) / n * (f(n - 1) + 1);
    return a[n];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif   
    a[1] = 1;
    b[1] = 1;
    for(int i = 2; i <= maxn; i++){
        b[i] = b[i - 1] * i;
        a[i] = (a[i - 1] /( i * (a[i - 1] + 1)));
        c[i] = a[i] * b[i];

    }
    
    cout << c[120] << " " << c[1000];

    return 0;
}
