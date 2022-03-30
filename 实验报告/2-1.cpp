#include <bits/stdc++.h>
using namespace std;

bool isdigit(char x){
    if(x>='0'&&x<='9') return true;
    return false;
}

bool isspace(char x){
    if(x==' ') return true;
    return false;
}

bool isalpha(char x){
    if((x>='a'&&x<='z')||(x>='A'&&x<='Z')) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    getline(cin,s);
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
