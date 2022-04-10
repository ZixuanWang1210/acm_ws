#include<bits/stdc++.h>
using namespace std;

int day[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
    int cnt=0;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int mm=1;mm<=12;mm++){
        for(int dd=1;dd<=day[mm];dd++){
            string s="2022";
            if(mm<10){
                s+='0';
            }
            string s1=to_string(mm);
            s+=s1;
            if(dd<10){
                s+='0';
            }
            s+=to_string(dd);

            for(int i=0;i<s.length();i++){
                if(s[i]+1==s[i+1]&&s[i+1]+1==s[i+2]){
                    cnt++;
                    cout<<s<<endl;
                }
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}