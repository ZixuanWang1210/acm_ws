#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

string s, t;
int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> s;
    int l = 0, r = n - 1;
    while(l < r){
        if(s[l] <= s[r]){
            t.append(t.size(), s[l]);
            l ++;
        }
        else{
            t.append(t.size(), s[r]);
            r --;
        }
    }
    cout << t;
    

    return 0;
}
