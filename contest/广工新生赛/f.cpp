#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

long long ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    string s;
    int n; cin >> n;
    cin >> s;
    for(int i = 0; i < s.length() - 2; i++){
        if(s[i] != 'o') continue;
        for(int j = i + 1; j < s.length() - 1; j++){
            if(s[j] != 's') continue;
            for(int k = j + 1; k < s.length(); k ++){
                if(s[k] == 'u') ans ++;
            }
        }
    }
    cout << ans;
    return 0;
}
