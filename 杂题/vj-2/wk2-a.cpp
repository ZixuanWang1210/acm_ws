#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

bool have_0(int x){
    string s=to_string(x);
    if(s.find('0')!=s.npos) return true;
    else return false;
}

pair<int,int> get(int x){
    int mx=-1,mn=0x3f3f3f3f;
    while(x){
        int t=x%10;
        mx=max(mx,t);
        mn=min(mn,t);
        x/=10;
    }
    return {mx,mn};
}

void sol(){
    int a,k; cin>>a>>k;
    k--;
    while(k--&&!have_0(a)){
        auto x=get(a);
        a+=(x.first*x.second);
    }
    cout<<a<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
