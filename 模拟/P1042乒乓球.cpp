#include <bits/stdc++.h>

using namespace std;

void print(int &w, int &l){
    cout << w << ":" << l << endl;
    w = 0, l = 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    string s, temp; 
    int w = 0, l = 0, total = 0;

    while(cin >> temp){
        s += temp;
    }
    //cout <<" " <<s.length() <<" ";
    for(int i = 0; i < s.length(); i++){
        //cout <<sizeof(s);
        if(s[i] == 'E') {print(w, l); break;}
        else if(s[i] == 'W') w++;
        else if(s[i] == 'L') l++;
        if((w >= 11 || l >= 11) && abs(l - w) >= 2) print(w, l);
    }

    cout << endl;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'E') {print(w, l); break;}
        else if(s[i] == 'W') w++;
        else if(s[i] == 'L') l++;
        if((w >= 21 || l >= 21) && abs(l - w) >= 2) print(w, l);
    }

    return 0;
}
