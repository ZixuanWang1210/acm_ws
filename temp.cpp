#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m;
string s;
const int maxn = 2000010, P = 131;
ull p[maxn], h1[maxn], h2[maxn];
int ans = 1;

int get(ull h[], int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int in = 1;
    while(cin >> s, s != "END"){
        cout << "Case " << in ++ << ": ";
        string temp; temp = "0";
        for(int i = 0; i < s.length(); i ++){
            temp += s[i];
            if(i != s.length() - 1) temp += "#";
        }
    
        s = temp;
        p[0] = 1;
        for(int i = 1, j = s.length()-1; i <= s.length() - 1; i ++, j--){
            p[i] = p[i -1] *P;
            h1[i] = h1[i-1]*P + s[i];
            h2[i] = h2[i-1]*P + s[j];
        }

        for(int i = 1; i <= s.length()-1; i ++){
            int len = ans;
            if(i + len > s.length()-1) break;
            while(1){
                if(i + len > s.length()-1) break;
                if(get(h1, i - len, len - 1) != get(h2, n - (i + len) + 1, n - (i + 1) + 1)) break;
                ans = max(ans, len);
                len ++;
            }
        }

        cout << ans << endl;
    }

    

    return 0;
}
