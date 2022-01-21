#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;

using namespace std;

int t;

unordered_set<ll> s;
unordered_set<ll> v;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        ll tot = 0;
        ll id = 0;
        for(ll i = 1; i <= m * n; i ++){
            id ++;
            char ch; cin >> ch;
            if(ch == 'P') s.insert(id), tot ++;
            if(ch == '*'){
                v.insert(id + 1);
                v.insert(id - 1);
                v.insert(id + 1 + n);
                v.insert(id - 1 + n);
                v.insert(id + n);
                v.insert(id - n);
                v.insert(id + 1 - n);
                v.insert(id - 1 - n);
            }
        }
        ll cnt = 0;
        for(auto x : s){
            ll ttt = x;
            if(v.find(ttt) != v.end()) cnt ++;
        }
        cout << tot - cnt << endl;

    }
    

    return 0;
}
