#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    while(n--){
        string s, s1, s2;
        cin >> s;
        int idx; cin >> idx;
        int len = s.length();

        s1 = s.substr(len - idx);
        s2 = s.substr(0, len - idx);
        cout << s1 + s2 << "\n";
    }
    

    return 0;
}
