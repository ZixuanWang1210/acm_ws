#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

unordered_map<int, string> mp;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    mp[0] = "ling";
    mp[1] = "yi";
    mp[2] = "er";
    mp[3] = "san";
    mp[4] = "si";
    mp[5] = "wu";
    mp[6] = "liu";
    mp[7] = "qi";
    mp[8] = "ba";
    mp[9] = "jiu";
    
    string s; cin >> s;

    for(int i = 0; i < s.length(); i++){
        if(i == 0 && s[i] == '-') cout << "fu ";
        else{
            int temp = s[i] - '0';
            cout << mp[temp] << " ";
        }
    }

    return 0;
}
