#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long 
using namespace std;

int x,a,b;
string s;
int ans;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>a>>b;
    cin>>s;

    for(int i=0;i<s.length();i++){
        if(s[i]=='0') x+=b;
        else{
            if(x-a<0){
                x+=b;
            }
            else{
                ans++;
                x-=a;
            }
        }
    }
    cout<<ans;

    return 0;
}
