#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e5 + 10;

int a[maxn];

struct point{
    int l, r, key;
    bool operator < (point& x) const{
        return key > x.key;
        if(key == x.key){
            return l < x.l;
        }
    }
};
vector<point> v;

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    
    int l = 1; 
    for(int i = 2; i <= n; i ++){
        if(a[i] < a[i - 1]){
            v.push_back({l, i - 1, a[i - 1] - a[l]});
            l = i;
        }
    }

    v.push_back({l, n, a[n] - a[l]});
    sort(v.begin(), v.end());
    for(auto x : v){
        if(x.key == v[0].key) cout << x.l << ' ' << x.r << ' ';
    }
    cout << endl;

}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
    

    return 0;
}
