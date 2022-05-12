#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int, int>
using namespace std;

const int maxn = 2500 + 10;
int c, l, ans;
vector<pii> v;
vector<int> cover;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // cout << endl;
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> c >> l;
    for(int i = 0; i < c; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    for(int j = 0; j < l; j++){
        int a, b; cin >> a >> b;
        for(int i = 1; i <= b; i++){
            cover.push_back(a);
        }
    }
    sort(v.begin(), v.end(), greater<pii>());
    sort(cover.begin(), cover.end());

    for(auto x : v){
        int ed = x.second;
        int idx = upper_bound(cover.begin(), cover.end(), ed) - cover.begin() - 1;
        auto st = upper_bound(cover.begin(), cover.end(), ed); st --;
        if(cover[idx] <= ed && cover[idx] >= x.first){
            // cout << *st << endl;
            cover.erase(st); ans ++;
            
        }
        
    }
    // cout << endl;
    cout << ans;


    return 0;
}
