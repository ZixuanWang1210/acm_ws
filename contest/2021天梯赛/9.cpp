#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

queue<char> a[200];
stack<char> stk;
queue<char> ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m,smax;
    cin>>n>>m>>smax;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=0;j<s.length();j++) a[i].push(s[j]);
    }
    int x;
    while(cin>>x,x!=-1){
        if(x==0){
            if(stk.size()==0) continue;
            else{
                char top=stk.top();
                stk.pop();
                ans.push(top);
            }
        }
        else{
            if(stk.size()==smax){
                char top=stk.top();
                stk.pop();
                ans.push(top);
            }
            // else{
            if(a[x].size()==0) continue;
            int top=a[x].front();
            a[x].pop();
            stk.push(top);
            // }
        }
    }
    while(ans.size()){
        cout<<ans.front();
        ans.pop();
    }

    

    return 0;
}
