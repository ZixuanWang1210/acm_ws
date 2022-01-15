#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

string s1, s2;
int cnt;

char change(char s){
    if(s == 'o') return '*';
    else return 'o';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;

    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i]){
            cnt ++;
            s1[i] = change(s1[i]);
            s1[i + 1] = change(s1[i + 1]);
        }
    }
    
    cout << cnt;

    return 0;
}
