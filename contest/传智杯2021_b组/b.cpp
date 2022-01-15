#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int n;
double a[1100];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    double mn = 0x3f3f3f3f, mx = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]), mn = min(mn, a[i]);
    }

    for(int i = 0; i < n; i++){
        int ans = (double)100 * ((double)a[i] - mn) / (mx - mn);
        cout << ans << " ";
    }
    

    return 0;
}
