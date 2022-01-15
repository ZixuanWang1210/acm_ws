#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    while(n--){
        int len; cin >> len;
        string s; cin >> s;
        int idx = 0;
        for(int i = len - 1; i >= 0; i --){
            if(s[i] == ')'){
                idx ++;
            }
            else break;
        }
        if(idx > len - idx)puts("Yes");
        else puts("No");
    }
    

    return 0;
}
