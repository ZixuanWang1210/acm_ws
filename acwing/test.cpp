#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

double a, ans;

int main(){
    cin >> a;
    double l = -10000, r = 10000;
    while(r - l > 1e-8){
        double mid = (l + r) / 2;
        if(mid * mid * mid >= a) r = mid;
        else l = mid;
    }

    cout << fixed << setprecision(6) << l;

    return 0;
}