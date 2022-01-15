#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    while(1){
        int cnt = 0;
        cin >> n;
        if(n == 0){
           return 0;
        }

        while(n >= 2){
            n -= 3;
            n += 1;
            cnt ++;
        }
        cout << cnt << "\n";
    }
    

    return 0;
}
