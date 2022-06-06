#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n,m;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int mx1=*max_element(v.begin()+1,v.end());
    cin>>m;
    vector<int> v1(m+1);
    for(int i=1;i<=m;i++){
        cin>>v1[i];
    }
    int mx2=*max_element(v1.begin()+1,v1.end());

    if(mx1==mx2){
        cout<<"Alice"<<endl<<"Bob"<<endl;
        return;
    }
    else{
        if(mx1>mx2){
            cout<<"Alice"<<endl<<"Alice"<<endl;
        }
        else cout<<"Bob"<<endl<<"Bob"<<endl;
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
