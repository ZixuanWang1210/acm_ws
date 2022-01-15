#include <bits/stdc++.h>
#define Test freopen("number.in", "r", stdin); freopen("number.out", "w", stdout);
typedef long long ll;

using namespace std;

ll n, k, ans;
ll l, r;

int main(){
    Test
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    while(n--){
        ans = 0;
        cin >> l >> r;
        ll flag = 0;
        do{
            if(l % k == 0 && flag == 0) flag = l / k;
            if(flag == 0) l ++;
            else{
                ans ++;
                flag ++;
                l = k * flag;
            }
        }while(l <= r);
        cout << ans << "\n";
    }
    

    return 0;
}
