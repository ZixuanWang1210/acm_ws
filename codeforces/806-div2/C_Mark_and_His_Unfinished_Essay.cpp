#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n,c,q;
    cin>>n>>c>>q;
    string s; cin>>s;
    s=' '+s;
    struct node{
        int l,r;
        int ll,rr;
    };
    vector<node> v;
    v.push_back({0,0,0,0});
    int len=n;
    while(c--){
        int l,r; cin>>l>>r;
        v.push_back({len+1,len+r-l+1,l,r});
        len+=r-l+1;
    }
    int cnt=v.size()-1;
    while(q--){
        int x; cin>>x;
        int idx=cnt;
        while(x>n){
            while(v[idx].l>x&&idx>1) idx--;
            x=x-v[idx].l+v[idx].ll;
            idx--;
        }
        cout<<s[x]<<endl;
    }

    // vector<int> vec;
    // vector<pii> ask;
    // ask.push_back({0,0});
    // ask.push_back({0,0});
    // vec.push_back(0);
    // vec.push_back(s.length());
    // s=' '+s;
    // while(q--){
    //     int l,r; cin>>l>>r;
    //     int len=r-l+1;
    //     len+=vec.back();
    //     vec.push_back(len);
    //     ask.push_back({l,r});
    // } 
    // while(q--){
    //     int x; cin>>x;
    //     int idx=prev(upper_bound(_all(vec),x))-vec.begin();
    //     x-=vec[idx];
    //     cout<<

    // }

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
