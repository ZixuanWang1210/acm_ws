#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

unordered_set<char> s;

void init(){
    s.clear();
    s.insert('e');
    s.insert('d');
    s.insert('g');
    s.insert('n');
    s.insert('b');
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    init();
    int cnt = 0, idx = -1;
    for(int i = 0; i < str.length(); i ++){

        if(s.find(str[i]) == s.end()){
            cnt = 0;
            init();
        }
        else{
            s.erase(str[i]);
            cnt ++;
        }

        if(cnt == 5){
            idx == i - 4;
            break;
        }
    }

    if(idx == -1){
        cout << str;
    }
    else{
        string t, tt;
        t = str.substr(0, idx);
        tt = str.substr(idx + 6);
        cout << t << "edgnb" << tt;
    }

    return 0;
}
