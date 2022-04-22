#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

struct node{
    int a,b; 
    bool operator<(const node&t) const{
        if(a==t.a) return b>t.b;
        else return a<t.a;
    }
};

void sol(){
    int n; cin>>n;
    vector<node> v(n+1);
    for(int i=1;i<=n;i++){
        int a,b; cin>>a>>b; 
        v[i]={a,b};
    }

    sort(v.begin()+1,v.begin()+1+n);
    vector<int> res(n+1);
    for(int i=1;i<=n;i++){
        if(v[i].a==v[i].b) res[i]=v[i].a;
        else{
            if(v[i+1].a==v[i].a&&v[i+1].b!=v[i].b){
                res[i]=min(v[i].b,v[i+1].b)+1;
            }
            else if(v[i+1].b==v[i].b&&v[i+1].a!=v[i].a){
                res[i]=min(v[i].a,v[i+1].a);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<v[i].a<<' '<<v[i].b<<' '<<res[i]<<endl;
    }
    cout<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
