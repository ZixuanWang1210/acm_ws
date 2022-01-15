#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, string>mp;
    string a, b;
    int c, sum;
    for(int i = 0; i < 3; i++){
        cin >> a >> b;
        mp[b] = a;
    }

    auto x = mp["mmmm"];

    cin >> sum;
    for(int i = 0; i < sum; i++){
        cin >> b;
        if(mp[b] != x){
            cout << mp[b] << endl;
        }
        else{
            cout << "Fake" << endl;
        }
    }

    return 0;
}