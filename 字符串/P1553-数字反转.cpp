#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll p[25];

ll rev(string x){
    ll ans = 0;
    int l = x.length();
    for(int i = 0; i < l; i++){
        ans += (x[i] - '0') * p[i];
    }
    return ans;
}

int main(){
    cin >> s;
    p[0] = 1;
    for(int i = 1; i < 25; i++){
        p[i] = p[i - 1] * 10;
    }

    int l = s.length();
    string temp;
    for(int i = 0; i < l; i++){
        if(s[i] == '.' || s[i] == '/' || s[i] == '%'){
            cout << rev(temp);
            cout << s[i];
            temp = "";
            continue;
        }
        temp += s[i];
        
    }
    cout << rev2(temp);

    return 0;
}