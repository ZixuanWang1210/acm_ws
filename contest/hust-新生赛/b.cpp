#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int maxn = 1e8 + 10;
int a[maxn], n, m;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
    }
    while(m--){
        int l, r; cin >> l >> r;
        int x; cin >> x;
        for(int i = l; i <= r; i++){
            a[i] &= x;
        }
    }

    for(int i = 1; i <= n; i ++){
        cout << a[i] << " ";
    }

    return 0;
}
