#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n,x; cin>>n>>x;
    int p=0;
    vector<int> v;
    while(n){
        v.push_back(n%x);
        n/=x;
    }
    p=v.size();
    int le=0;
    for(int i=1;i<=p;i++){
        le+=(v[i-1]+1);
    }
    cout<<le<<endl;
    for(int i=1;i<=p;i++){
        for(int j=0;j<v[i-1];j++){
            cout<<"1 a"<<endl;
        }
        cout<<"2 b"<<endl;
    }

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
