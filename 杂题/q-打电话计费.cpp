#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

double x;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> x;
    if(x <= 0.5){
        cout << 3;
    }
    else{
        double res = (double)x - 0.5;
        int t = ceil(res / 0.2);
        cout << 3 + t;
    }

    return 0;
}
