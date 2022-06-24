#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    int mn1=inf,mn2=inf;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(i&1) mn1=min(mn1,v[i]);
        else mn2=min(mn2,v[i]);
    }
    if(n&1) cout<<"Mike"<<endl;
    else{
        if(mn1>mn2) cout<<"Mike"<<endl;
        else if(mn1<mn2) cout<<"Joe"<<endl;
        else{
            for(int i=1;i<=n;i++){
                if(v[i]==mn1){
                    if(i&1) cout<<"Joe"<<endl;
                    else cout<<"Mike"<<endl;
                    return;
                }
            }
        }
    }
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
