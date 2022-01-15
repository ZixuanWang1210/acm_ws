#include<bits/stdc++.h>
using namespace std;

string s;
int n,ans;

int main(){
    getline(cin, s);
    int l = s.length();
    for(int i = 0; i < l; i++){
        if(s[i]>='A'&&s[i]<='Z') 
           ans++;
        if(s[i]>='a'&&s[i]<='z')  
           ans++;
        if(s[i]>='0'&&s[i]<='9') 
           ans++;
    }

    std::cout << ans;

    return 0;
}