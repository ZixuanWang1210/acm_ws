#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int,int>
using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    vector<int> a(n+1),b(n+1);
    vector<pii> v(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        v[i]={a[i],b[i]};
    }
    sort(v.begin()+1,v.begin()+1+n);

    for(int i=1;i<=n;i++){
        int xa=v[i].first,xb=v[i].second;
        if(k>=xa) k+=xb;
        else{
            cout<<k<<endl;
            return;
        }
    }
    cout<<k<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
