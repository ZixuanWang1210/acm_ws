#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
typedef unsigned long long ull;

using namespace std;

deque<int> q;

ull n,x;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin>>n>>x>>s;

    while(x){
        if(x&1) q.push_front(1);
        else q.push_front(0);
        x>>=1;
    }

    for(int i=0;i<s.length();i++){
        if(s[i]=='U'){
            q.pop_back();
        }
        else if(s[i]=='L'){
            q.push_back(0);
        }
        else{
            q.push_back(1);
        }
    }
    // string ans;
    ull base=1,ans=0;
    while(q.size()){
        int t=*prev(q.end());
        // cout<<t<<endl;
        ans+=base*t;
        base*=2;
        q.pop_back();
        // ans+=q.front()+'0';
        // q.pop_front();
    }
    cout<<ans;

    

    return 0;
}
