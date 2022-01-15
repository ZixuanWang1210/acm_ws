#include<bits/stdc++.h>
using namespace std;

string s;
int ans;

int trans(char x){
    return x - 'A';
}

int main(){
    cin >> s;
    int l = s.length();

    for(int i = 0; i < l; i++){
        if(s[i] == '('){
            int tmp = 0;
            while(s[i] != ')'){
                i ++;
                tmp += trans(s[i]);
            }
        }
        
    }


    return 0;
}