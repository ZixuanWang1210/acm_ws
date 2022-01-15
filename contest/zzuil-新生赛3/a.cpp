#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int, int> pii;
using namespace std;

int n;
int m;
ll ans;
// vector<pii> v;
unordered_map<int, int> mp;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> n >> m;
    while(n--){
        int id, a;
        cin >> id >> a;
        mp[id] = a;
    }
    // sort(v.begin(), v.end());
    while(m--){
        int k; cin >> k;
        int _min = 0x3f3f3f3f;
        while(k--){
            int temp; cin >> temp;
            _min = min(_min, mp[temp]);
            mp.erase(temp);
        }
        ans += _min;
    }

    for(auto x : mp){
        ans += x.second;
    }
    cout << ans;
    return 0;
}
