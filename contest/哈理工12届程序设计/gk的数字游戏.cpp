#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define rep(x,a,b) for(int x=a; x<=b; x++)
#define LL long long

LL n,m;

void solve(){
    cin >> n >> m;
    LL res = 0;

    while(n!=m){
        if(n>=m) {
            LL d=n-m;
            LL s = ceil((double)d/m);
            res += s;
            n -= s*m;
        }
        else {
            LL d=m-n;
            LL s = ceil((double)d/n);
            res += s;
            m -= s*n;
        }
    }
    res++;
    cout << res << endl;
}

int main()
{
    int _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
