#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

string s;
int base;
unordered_map<char,char> mp;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    mp['C']='1',mp['D']='2',mp['E']='3',mp['F']='4',mp['G']='5',mp['A']='6',mp['B']='7';
    for(int i=0;i<s.length();i++){
        if(s[i]=='<'){
           base --;
        }
        else if(s[i]=='>'){
            base ++;
        }
        else{
            cout<<mp[s[i]];
            if(base<0){
                int ttt=-base;
                for(int i=0;i<ttt;i++){
                    cout<<'.';
                }
            }
            else{
                for(int i=0;i<base;i++){
                    cout<<'*';
                }
            }
        }
    }
    

    return 0;
}
