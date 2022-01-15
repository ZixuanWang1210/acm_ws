#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n, l ,r, ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> l >> r;
    
    if(l < r <= n){
        cout << r;
    }
    else if(l <= n <= r){

        cout << max(n - r, r % n);

    }
    else{
        int t = l / n;
        int tt = r / n;
        if(t == tt){
            cout << r - n;
        }
        if(tt > t + 1){
            cout << n - 1;
        }
        else{
            int aa = n * (t + 1) - 1 - n * t;
            int aaa = r - n * (t + 1);
            cout << max(aa,aaa);
        }

    }

    return 0;
}
