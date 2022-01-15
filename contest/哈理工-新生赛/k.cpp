#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

string s;
ll cnt = 0;
int a[3] {};

ll q_mi(int a, int b, int p){
    ll res = 1;
    a %= p;

    while(b){
        if(b & 1){
            res = res * a % p;
        }
        b >>= 1;
        a = a * a % p;
    }

    return res;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] = 'J' && s[i + 1] == 'a' && s[i + 2] == 'y' && i + 2 <= s.length() - 1){
            cnt ++;
            i += 2;

        }
        else if(s[i] == 'j' || s[i] == 'J')  a[0] ++;
        else if(s[i] == 'a' || s[i] == 'A') a[1] ++;
        else if(s[i] == 'y' | s[i] == 'Y') a[2] ++;
    }

    ll temp = 0;
    if(a[0] > 0 && a[1] > 0 && a[2] > 0){
        temp = 1;
    }
    else{
        cnt --;
    }

    if(cnt <= 0 && temp == 1){
        cout << 1;
        return 0;
    }
    else if(cnt <= 0 && temp == 0){
        cout << 0;
        return 0;
    }
    else cout << q_mi(2, cnt, 1e9 + 7);

    

    return 0;
}
