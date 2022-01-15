#include<bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; 
    scanf("%d", &t);
    // cin >> t;
    while(t--){
        long long a, b; 
        scanf("%lld%lld",&a, &b);
        // cin >> a >> b;
        long long ans = (a + b)*(b - a + 1) / 2;
        printf("%lld", ans);
        // cout << (a + b)*(b - a + 1) / 2;
        puts("");
    }

    return 0;
}