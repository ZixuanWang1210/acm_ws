#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin>>s;
    if(s.length()==4){
        int yy=(s[0]-'0')*10+(s[1]-'0');
        if(yy<22){
            cout<<20<<s[0]<<s[1]<<'-'<<s[2]<<s[3]<<endl;
        }
        else{
            cout<<19<<s[0]<<s[1]<<'-'<<s[2]<<s[3]<<endl;
        }
    }
    else{
        cout<<s[0]<<s[1]<<s[2]<<s[3]<<'-'<<s[4]<<s[5]<<endl;
    }
    

    return 0;
}
