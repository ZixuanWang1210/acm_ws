#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;


int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    scanf("%d", &n);
    while(n--){
        double p; scanf("%lf", &p);
        if(p < 100) printf("%0.2f\n", p);
        else if(p >= 100){
            // p = p * 0.9;
            double res = p - 100;
            double ans = 90.000 + 0.950 * res;
            // cout << ans;
            printf("%0.2f\n", ans);
            // cout << fixed << setprecision(2) << ans + 0.005  << endl;
        }
    }
    

    return 0;
}
