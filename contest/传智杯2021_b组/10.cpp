#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1100;
map<int, int> mp;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int n, k; cin >> n >> k;
    while(n--){
        int opt; cin >> opt;
        if(opt == 1){
            int num; cin >> num;
            while (num--){
                int x, y; cin >> x >> y;
                mp[x] = y;
            }
        }
        else{
            int x, mn, mx;
            cin >> x >> mn >> mx;
            int temp = mp[x];
            if(temp >= mn && x <= mx) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    

    return 0;
}
