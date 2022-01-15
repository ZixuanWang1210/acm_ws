#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

int t;

bool judge(int x){
    // bool x[10] = {false};
    int temp = x;
    bool flag = true;
    while(temp){
        int t = temp % 10;
        temp /= 10;
        if(t != 0 && x % t != 0){
            return false;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> t;
    while(t--){
        int n; cin >> n;
        while(!judge(n)){
            n ++;
        }
        cout << n << endl;
    }

    return 0;
}
