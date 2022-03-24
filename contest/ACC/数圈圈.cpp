#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


int cnt=0;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    stack<int> stk;
    if(n==0){
        cout<<1<<endl;
        return 0;
    }
    while(n){
        stk.push(n%16);
        n/=16;
    }
    while(stk.size()){
        int t=stk.top();
        // cout<<t<<endl;
        stk.pop();
        char tmp;
        if(t<10){
            tmp='0'+t;
        }
        else{
            tmp='A'+t-10;
            // cout<<tmp<<endl;
        }
        if(tmp=='0'||tmp=='4'||tmp=='6'||tmp=='9'||tmp=='A'||tmp=='D') cnt++;
        else if(tmp=='8'||tmp=='B') cnt+=2;
    }
    cout<<cnt<<endl;
    return 0;
}
