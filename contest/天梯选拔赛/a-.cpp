#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

string s,rs;
int len;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>s;
    rs=s;
    reverse(rs.begin(),rs.end());
    len=s.length();
    char a=s[0],b=s[len-1];
    int bg=rs.find(a);
    int ed=s.find(b);
    if(ed!=bg){
        cout<<"Just a legend";
        return 0;
    }
    bg=len-bg-1;
    for(int i=0;i<=ed;i++){
        if(s[i]!=s[bg+i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    string check;

    for(int i=0;i<=ed;i++){
        check+=s[i];
    }
    string mid=s.substr(ed+1,len-2*(ed+1));
    cout<<mid<<endl;
    if(mid.find(check)==mid.npos){
        cout<<"Just a legend"<<endl;
    }
    else cout<<check;
    
    
   
    return 0;
}
