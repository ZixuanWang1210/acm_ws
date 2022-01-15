#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

bool is_primer(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0){
            return false;
        }

    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int n;
    cin >> n;
    while(n--){
        int x; cin >> x;
        if(is_primer(x)) puts("Yes");
        else puts("No");
    }

    return 0;
}
