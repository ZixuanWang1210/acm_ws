#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int t;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> t ;
    while(t--){
        int xa, ya, xb, yb, xp, yp;
        cin >> xa >> ya >> xb >> yb >> xp >> yp;
        int ans = abs(xa - xb) + abs(ya - yb);
        if((xa == xb && xb == xp && 
            ((ya < yp && yp < yb) || 
            (ya > yp && yp > yb)))|| 
            ya == yb && yb == yp && 
            ((xa < xp && xp < xb) || 
            (xa > xp && xp > xb))){
        // if(xa == xb == xp || ya == yb == yp){
            
            ans += 2;
            cout << ans << endl;;
        }
        else{
            cout << ans << endl;;
        }
    }



    return 0;
}
