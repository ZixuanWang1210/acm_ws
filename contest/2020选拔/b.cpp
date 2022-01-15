#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans;

ll _xor(ll a){
    return a ^ (a - 1);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        ans += _xor(i);
    }
    cout << ans;
    return 0;
}