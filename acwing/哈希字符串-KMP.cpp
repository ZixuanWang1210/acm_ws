#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int P = 131;
const int maxn = 1e6 + 10;

char p[maxn], s[maxn];
ull hp[maxn], hs[maxn], a[maxn];
int n, m;

ull get(ull s[], int l, int r){
    return s[r] - s[l - 1] * a[r - l + 1];
}

int main(){
    cin >> n;
    scanf("%s", p + 1);
    cin >> m;
    scanf("%s", s + 1);

    a[0] = 1;
    for(int i = 1; i <= m; i++){
        a[i] = a[i - 1] * P;
        hs[i] = hs[i - 1] * P + s[i];
    }

    for(int i = 1; i <= n; i++){
        hp[i] = hp[i - 1] * P + p[i];
    }

    ull te = get(hp, 1, n);

    for(int i = 1; i <= m - n + 1; i++){
        if(get(hs, i, i + n - 1) == te) cout << i - 1 << " ";
    }

    return 0;
}