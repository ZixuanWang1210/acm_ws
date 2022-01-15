#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
const int maxn = 110;
int a[maxn];

int get(int x){
    if(x < 2){
        cout << x << " " << 1 << endl;;
        return 0;
    }
    for(int i = 2; i <= x / i; i++){
        int cnt = 0;
        while(x % i == 0){
            x /= i;
            cnt ++;
        }
        if(cnt > 0) cout << i << ' ' << cnt << endl;;
    }
    if(x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    while(n--){
        int x; cin >> x;
        get(x);
    }
    

    return 0;
}
