#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int maxn = 5e5 + 10;
int a[maxn];
int n;
int cnt = 0, idx = 1, ans = 0, sum = 0;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i] % 2 == 0){
            cnt ++;
        }
        else{
            sum = cnt * (cnt + 1) / 2 + sum;
            cnt = 0;
        }
    }
    sum = cnt * (cnt + 1) / 2 + sum;
    cnt = 0;
    ans = n * (n + 1) / 2 - sum;
    
    cout << ans;
    return 0;
}
