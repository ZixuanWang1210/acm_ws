#include<bits/stdc++.h>
using namespace std;

map<char,int> mp;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    for(int i=1;i<=26;i++){
        mp[s1[i-1]]=i;
    }
    int idx=0,ans=1;
    for(int i=0;i<s2.length();i++){
        int num=mp[s2[i]];
        // cout<<num;
        if(idx>=num) ans++,idx=num;
        else idx=num;
    }
    cout<<ans;

    return 0;
}