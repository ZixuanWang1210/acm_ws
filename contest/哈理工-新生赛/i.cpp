#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n, ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    bool tt = true;
    int re = -1;
    int rea, reb, rew, w;
    while(n--){
        int a, b; cin >> a >> b;
        if((a == 0 || b == 0) && tt) ans ++;
        if(re = -1) 

        w = (a > b) ? 0 : 1;

        rea = a, reb = b;
        tt = false;
    }
    

    return 0;
}
