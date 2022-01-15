#include <bits/stdc++.h>
using namespace std;

int a[100010], dp1[100010], dp2[100010];
int n, ans1, ans2;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    while(cin >> a[++n]); n--;
    for(int i = n; i >= 1; i--){
        dp1[i] = 1;
        for(int j = i + 1; j <= n; j++){
            if(a[j] <= a[i]) dp1[i] = max(dp1[i], dp1[j]+1);
        }
        ans1 = max(ans1, dp1[i]);
    }
    
    for(int i = 1; i <= n; i++){
        dp2[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]) dp2[i] = max(dp2[i], dp2[j] + 1);
        }
        ans2 = max(ans2, dp2[i]);
    }
    cout << ans1 <<endl<< ans2;
    return 0;
}
