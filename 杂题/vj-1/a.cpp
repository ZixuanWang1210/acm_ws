#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long

using namespace std;

void sol(){
    int n ;cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    auto x=max_element(v.begin()+1,v.begin()+1+n);
    if(*x==1) *x=2;
    else *x=1;

    sort(v.begin()+1,v.begin()+n+1);
    for(int i=1;i<=n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
