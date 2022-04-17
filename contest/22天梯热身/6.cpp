#include<bits/stdc++.h>
using namespace std;


void sol(){
    string s; cin>>s;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            if(s[i+1]==s[i]+('a'-'A')){
                continue;
            }
            if(s[i+1]==s[i]+1){
                continue;
            }
            cout<<"N"<<endl;
            return;
        }
        if(s[i]>='a'&&s[i]<='z'){
            if(s[i+1]==s[i]-('a'-'A')){
                continue;
            }
            // if(s[i-1]>='a'&&s[i-1]<='a'){
            //     if(s[i-1]==s[i+1]){
            //         continue;
            //     }
            // }
            // if(s[i-1]>='A'&&s[i-1]<='Z'){
            //     if(s[i+1]==s[i-1]+('a'-'A')){
            //         continue;
            //     }
            // }
            if(s[i+1]==s[i]-1){
                continue;
            }

            cout<<"N"<<endl;
            return;
        }
    }
    cout<<"Y"<<endl;
    return;
}

int main(){
    int t; cin>>t;
    while(t--) sol();
    
    return 0;
}