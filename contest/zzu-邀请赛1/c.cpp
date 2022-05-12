#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

struct node{
    int num,a,b,c;
    string s;
    bool operator<(const node &t) const{
        if(s==t.s)
        return num<t.num;
        else return s<t.s;
    }
};

set<node> mp;
int s11,s12,s13,s21,s22,s23,s31,s32,s33;

void sol() {
    int _=3;
    while(_--){
        int n; cin>>n;
        for(int i=1;i<=n;i++){
            string s; int a,b,c,d;
            cin>>s>>a>>b>>c>>d;
            mp.insert({a,b,c,d,s});
        }
    }
    vector<node> v1,v2,v3;

    for(auto x:mp){
        if(x.s[0]=='s'){
            v1.push_back(x);
            s11+=x.a,s12+=x.b,s13+=x.c;
        }
        if(x.s[0]=='j'){
            v2.push_back(x);
            s21+=x.a,s22+=x.b,s23+=x.c;
        }
        if(x.s[0]=='l'){
            v3.push_back(x);
            s31+=x.a,s32+=x.b,s33+=x.c;
        }
    }
    cout<<v1.size()<<' ';
    cout<<s11<<' '<<s12<<' '<<s13<<endl;
    for(auto x:v1){
        cout<<x.s<<' '<<x.num<<" "<<x.a<<' '<<x.b<<" "<<x.c<<endl;
    }

    cout<<v2.size()<<' ';
    cout<<s21<<' '<<s22<<' '<<s23<<endl;
    for(auto x:v2){
        cout<<x.s<<' '<<x.num<<" "<<x.a<<' '<<x.b<<" "<<x.c<<endl;
    }

    cout<<v3.size()<<' ';
    cout<<s31<<' '<<s32<<' '<<s33<<endl;
    for(auto x:v3){
        cout<<x.s<<' '<<x.num<<" "<<x.a<<' '<<x.b<<" "<<x.c<<endl;
    }




}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    // cin>>_;
    while (_--) {
        sol();
    }

    return 0;
}
