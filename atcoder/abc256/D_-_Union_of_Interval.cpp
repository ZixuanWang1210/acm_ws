#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int, int>
using namespace std;
const int maxn = 0x3f3f3f3f;

vector<pii> v;

void merge(){
    vector<pii> opt;
    int st = -maxn, ed = -maxn;
    for(auto x : v){
        if(ed < x.first){
            if(st != -maxn) opt.push_back({st, ed});
            st = x.first, ed = x.second;
        }
        else{
            ed = max(ed, x.second);
        }
    }
    if(ed != -maxn) opt.push_back({st, ed});
    
    v = opt;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        v.push_back({l ,r});
    }
    sort(v.begin(), v.end());

    merge();

    // cout << v.size();
    for(auto x:v){
        cout<<x.first<<' '<<x.second<<endl;
    }
   

    return 0;
}
