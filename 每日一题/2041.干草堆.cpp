#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e6 + 10;
int a[maxn], s[maxn];
int n, k;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> k;
    int _max;
    while(k --){
        int l, r; cin >> l >> r;
        _max = max(_max, max(l, r));
        a[l] ++; a[r + 1] --;
    }
    
    for(int i = 1; i <= _max; i++){
        s[i] = s[i - 1] + a[i];
    }
    
    sort(s, s + _max + 1);
    int idx = (1 + _max) / 2;
    cout << s[idx];

    return 0;
}
