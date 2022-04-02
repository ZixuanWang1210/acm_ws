#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void f(int x){
	double k = (x + 1) * 1.0 / x;
	double ans = pow(k, x);
	printf("%.3lf\n", ans);
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    if(n>1000000)cout<<2.718<<endl;
    else f(n);

    return 0;
}
