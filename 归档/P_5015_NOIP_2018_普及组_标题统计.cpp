#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt=0;
    string s; getline(cin,s);
    for(int i=0;i<s.length();i++){
        char x=s[i];
        if(x>='A'&&x<='Z') cnt++;
        else if(x>='a'&&x<='z') cnt++;
        else if(x>='0'&&x<='9') cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}