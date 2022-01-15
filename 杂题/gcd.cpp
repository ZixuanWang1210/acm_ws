#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

set<int> s;
int n, m;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        s.insert(temp);
    }

    while(m--){
        int x; cin >> x;
        if(s.find(x) != s.end()){
            cout << "YES" << "\n";
        }
        else cout << "NO" << "\n";
    }


    return 0;
}
