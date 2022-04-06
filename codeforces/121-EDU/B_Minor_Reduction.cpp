#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;

using namespace std;

void sol(){
    string s; cin>>s;
    bool bz=true;
    for(int i=s.size()-2;i>=0;i--){
        int a=s[i]-'0',b=s[i+1]-'0';
        if(a+b>=10){
            int tt=a+b;
            b=tt%10;
            a=tt/10;
            s[i+1]=b+'0';
            s[i]=a+'0';
            bz=false;
            break;
        }
    }
    if(bz){
        int a=s[0]-'0',b=s[1]-'0';
        int tt=a+b;
        a=0;
        b=tt;
        s[0]=a+'0';
        s[1]=b+'0';
        for(int i=1;i<s.size();i++){
            cout<<s[i];
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
