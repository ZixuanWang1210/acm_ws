#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n, m, k;

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int hh, mm;
    scanf("%d:%d", &hh, &mm);
    // cout << hh << mm;

    scanf("%d %d %d", &n, &m, &k);

    int temp = 0;
    temp = n / k * m;

    mm += temp;
    hh += mm / 60;
    mm %= 60;

    // cout << hh << mm;
    if(hh < 10) printf("0");
    printf("%d:%d", hh, mm);
    return 0;
}
