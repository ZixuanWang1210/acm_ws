#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

#define pii pair<int, int>
int n;
vector<pii> v;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> n;
    for(int i = 0; i < n; i ++){
        int w, s; cin >> w  >> s;
        v.push_back({w + s, w});
    }
    sort(v.begin(), v.end());
    int sum = 0;
    int ans = -1e9;
    for(auto x : v){
        int s = x.first - x.second;
        ans = max(sum - s, ans);
        sum += x.second;
    }
    cout << ans;

    return 0;
}
