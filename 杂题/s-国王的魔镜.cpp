    #include <bits/stdc++.h>
    // typedef long long ll;
    // typedef unsigned long long ull;

    using namespace std;

    string s;

    bool cmp(string s){
        if(s.length() == 1) return false;
        string s1 = s;
        string s2 = s;
        reverse(s1.begin(), s1.end());
        if(s1 == s2) return true;
        else return false;
    }

    int main(){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        // #ifdef LOCAL
        // freopen("in.txt","r",stdin);
        // freopen("out.txt","w",stdout);
        // #endif
        // cin >> s;

        // int len = s.length();

        cin >> s;
        int len = s.length();

        while(1){
            if(cmp(s)){
                len = len >> 1;
                s = s.substr(0, len);
            }
            else break;
        }
        cout << len;
        // int ans = 0;
        // while(1){
        //     int l = 0, r = s.length() - 1;
        //     while(l <= r){
        //         if(s[l] == s[r]) ans ++, l ++, r --;
        //         else{
        //             cout << s.length();
        //             return 0;
        //         }
        //     }
        //     s = s.substr(0, l);
        // }

        return 0;
    }
