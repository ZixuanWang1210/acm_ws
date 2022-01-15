#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;
map<char, int> mp;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    int t; cin >> t;

    while(t--){
        mp.clear();
        string s; cin >> s;
        int n; cin >> n;
        int ans = 0x3f3f3f3f;
        for(int i = 0, j = 0; i < s.length(); i++){
            mp[s[i]] ++;
            while(mp[s[i]] == n){
                ans = min(ans, i - j + 1);
                mp[s[j]] --;
                j ++;
            }
        }
        if (ans == 0x3f3f3f3f) cout << -1 << endl;
        else cout << ans << endl;

    }
    

    return 0;
}
