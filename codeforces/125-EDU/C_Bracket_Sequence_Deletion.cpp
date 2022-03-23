// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long

using namespace std;

void sol(){
    int len; cin>>len;
    string ss; cin>>ss;

    int cnt=0;

    for(int i=0;i<ss.length();i++){

        if(ss[i]=='('&&ss[i+1]==')'){
            ss.erase(0,2);
            i=-1;
            cnt++;
        }
        else if(ss[i]=='('&&ss[i+1]=='('){
            ss.erase(0,2);
            i=-1;
            cnt++;
        }
        else if(ss[i]==')'&&ss[i+1]==')'){
            ss.erase(0,2);
            i=-1;
            cnt++;
        }
        else if(ss[i]==')'&&ss[i+1]=='('&&ss[i+2]==')'){
            ss.erase(0,3);
            i=-1;
            cnt++;
        }
        else if(ss[i]==')'&&ss[i+1]=='('&&ss[i+2]==')'){
            ss.erase(0,3);
            i=-1;
            cnt++;
        }
        else if(ss[i]==')'&&ss[i+1]=='('){
            char bz=ss[i+2];
            i+=2;
            while(i<ss.length()){
                if(ss[i]=='('&&ss[i+1]==')'){
                    cnt++;
                    ss.erase(0,i+2);
                    i=-1;
                    break;
                }
                if(ss[i]!=bz){
                    cout<<cnt<<' '<<ss.length()+1<<endl;
                }
                i++;
            }  
        }
    }
    cout<<cnt<<' '<<ss.length()<<endl;
}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
