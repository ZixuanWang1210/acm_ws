#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int maxn = 110;
int n, sum, ans;
int a[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    int avg = sum / n;

    for(int i = 1; i <= n; i++){
        if(a[i] != avg) a[i + 1] += a[i] - avg, ans ++;
    }
    
    cout << ans << endl;
    return 0;
}
