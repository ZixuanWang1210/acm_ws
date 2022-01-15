#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

vector<int> v;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int w; cin >> w;
    cout << v[v.size() - w];
    

    return 0;
}
