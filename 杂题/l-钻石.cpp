#include <bits/stdc++.h>
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int n, x1, y1, x, y;
    ll sumx = 0, sumy = 0;
    cin >> n >> x1 >> y1 >> x >> y;
    
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        sumx = max(sumx, (ll)a), sumy += b;        
    }
    
    if(sumx <= x1){
        ll res = (x1 - sumx) / x * y;
        y1 += res;
        if(y1 >= sumy){
            cout << 1 << "\n" << x1 + (y1 - sumy) / y * x  << "\n";
        }
        else cout << 0 << "\n";
    }
    else{
        ll res = (y1 - sumy) / y * x;
        x1 += res;
        if(x1 >= sumx){
            cout << 1 << "\n" << x1 - sumx << "\n";
        }
        else cout << 0 << "\n";
    }

    return 0;
}
