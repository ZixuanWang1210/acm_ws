#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

stack<char> s;
vector<char> v;
int idx=0,ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<s.length();i++){

        if(s[i]=='z'||s[i]=='f'||s[i]=='c') v.push_back(s[i]),idx++;
        if(s[i]=='c'){
            if(idx-3<0) continue;
            if(v[idx-2]=='f'&&v[idx-3]=='z'){
                ans++;
                v.erase(v.end()-3,v.end());
                idx-=3;
            }
        }
    }
    cout<<ans<<endl;
    

    return 0;
}
