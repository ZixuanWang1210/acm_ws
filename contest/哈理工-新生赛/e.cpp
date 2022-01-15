#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
vector<int> v;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    int f = (n >> 0) & 1;
    if(f == 1){
        cout << -1;
        return 0;
    }
    else{
        int idx = 0;
        while(n){
            idx ++;
            int t = (n >> idx) & 1;
            if(t == 1)
                v.push_back(idx);
        }
    }
    sort(v.begin(), v.end());
    for(auto x : v){
        cout << x << " ";
    }

    return 0;
}
