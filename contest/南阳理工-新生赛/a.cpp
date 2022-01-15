#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

signed main(){
    ios::sync_with_stdio(false);
    unsigned long long t; cin >> t;
    while(t--){
        string s; cin >> s;
        unsigned long long n = 0, b = 1, ans = 0;

        for(int i = s.length() - 1; i != -1; i--){
            if(s[i] != '0')
                ans  += (s[i] - '0') * b;
            b *= 2;
        }
        cout << ans << endl;
    }

    return 0;
}