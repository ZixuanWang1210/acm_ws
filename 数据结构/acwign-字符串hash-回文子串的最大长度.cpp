#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
typedef unsigned long long ull;


using namespace std;

const int maxn = 10, P = 131;
ull p[maxn], h1[maxn], h2[maxn];
string s;

int main(){
    cin >> s;
    s = '0' + s;
    string temp; temp = "0";
    for(int i = 1; i <= s.length() - 1; i ++){
        temp += s[i];
        if(i != s.length()-1) temp+='#';
    }
    s = temp;
    cout << temp << endl;

    for(int i = 1, j = s.length()-1; i <= s.length() - 1; i ++, j--){
        cout << i << "--" << j << endl;
        p[i] = p[i -1] *P;
        h1[i] = h1[i-1]*P + s[i];
        h2[i] = h2[i+1]*P + s[i];
    }

    int mid, len; cin >> mid >> len;
    int hash1 = h1[mid] - h1[mid - len - 1]*p[len+1];
    int hash2 = h2[mid] - h2[mid + len + 1]*p[len+1];
    cout << hash1 << ' '<< hash2 ;
    

    return 0;
}
