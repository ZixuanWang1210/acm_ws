#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin>>s;
    int alp=0,dig=0,els=0,spa=0;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])) dig++;
        else if(isalpha(s[i])) alp++;
        else if(isspace(s[i])) spa++;
        else els++;
    }
    cout<<alp<<' '<<dig<<' '<<spa<<' '<<els<<endl;

    return 0;
}
