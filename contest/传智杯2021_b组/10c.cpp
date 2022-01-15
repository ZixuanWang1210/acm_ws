#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int, int> 

using namespace std;

vector<int> v[110];

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
                v[x].push_back(y);
            }
        }

        else{
            int x, mn, mx;
            cin >> x >> mn >> mx;
            int ans = 0;
            for(auto vec : v[x]){
                if(vec >= mn && vec <= mx) ans ++;
            }
            cout << ans << endl;
        }
    }
    

    return 0;
}
