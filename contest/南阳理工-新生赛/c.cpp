#include<bits/stdc++.h>
using namespace std;
const int maxn = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
vector<pii> v, opt;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        v.push_back({l, r});
    }

    sort(v.begin(), v.end());

    int st = -maxn, ed = -maxn;

    for(auto x : v){
        st = x.first;
        if(st > ed){
            ed = x.second;
            opt.push_back({st, ed});
        }
        else {
            ed = max(ed, x.second);
        }
    }

    v = opt;
    cout << v.size() << endl;
    for(auto x : v){
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}