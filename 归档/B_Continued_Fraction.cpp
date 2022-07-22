#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

void sol(){
    int a,b; cin>>a>>b;
    int cnt=0;
    vector<int> res;
    if(a==1){
        cout<<"1 0 ";
        cout<<b<<endl;
        return;
    }
    while(a!=1){
        int aa=a/b;
        // cout<<aa;
        res.push_back(aa);
        a-=aa*b;
        swap(a,b);
    }

    cout<<res.size()-1<<' ';
    for(auto x:res) cout<<x<<" ";

    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
