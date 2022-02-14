#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
typedef unsigned long long ll;

using namespace std;

ll x,y;

string tos(ll x){
    string ans;
    while(x){
        int t=x&1;
        ans+=('0'+t);
        x=x>>1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x;
    string ss=tos(x);
    for(int i=3;i;i++){
        if(i%2==0) continue;
        ll t=x*i;
        if(t>1e19) break;
        string sss=tos(t);
        if(sss.find(ss)!=sss.npos){
            cout<<t;
            return 0;
        }
        cout<<i<<endl;
    }
    // cout<<tos(x);

    return 0;
}
