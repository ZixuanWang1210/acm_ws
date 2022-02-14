#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

double a,x;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x;
    double tt=x*x*4/3;
    a=tt*sqrt(tt);
    cout<<fixed<<setprecision(8)<<a;
    

    return 0;
}
