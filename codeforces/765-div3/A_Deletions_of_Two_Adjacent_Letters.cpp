#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    string s;
    char c; 
    cin>>s>>c;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]==c){
            int a=i,b=len-i-1;
            // cout<<a<<' '<<b<<endl;
            if(a%2==0&&b%2==0){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
