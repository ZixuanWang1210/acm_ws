#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string s1 = "ylnywys";
    int idx = 0, ans = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == s1[idx]){
            idx ++;
            if(idx == 6){
                ans ++;
                idx = 0;
            }
        }
        else{
            if(s[idx - 1] == 'y') idx = 1;
            else idx = 0;

        }
    }
    cout << ans;
    return 0;
}