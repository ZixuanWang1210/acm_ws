#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int, int>
using namespace std;

priority_queue<pii> q;
vector<pii> v;
int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    for(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        v.push_back({l ,r});
    }
    sort(v.begin(), v.end());

    for(auto x : v){
        if(q.empty()) q.push(x);
        else{
            
        }
    }
    

    return 0;
}
