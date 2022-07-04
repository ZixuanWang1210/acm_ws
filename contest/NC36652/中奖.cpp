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


struct node{
    int hh,mm,cc,id;
    bool operator<(const node & t) const {
        if(cc==t.cc){
            if(hh!=t.hh) return hh<t.hh;
            else return mm<t.mm;
        }
        return cc>t.cc;
    }
};

vector<node> pq;
void sol(){
    int n; cin>>n;
    int m; cin>>m;
    for(int i=1;i<=n;i++){
        int a,b,c; cin>>a>>b>>c;
        pq.push_back({a,b,c,i});
    }
    sort(_all(pq));
    // while(pq.size()&&m--){
    //     // cout<<pq.top().id<<endl;
    //     cout<<pq.top().hh<<" "<<pq.top().mm<<' '<<pq.top().cc<<endl;
    //     pq.pop();
    // }
    for(int i=0;i<m;i++){
        cout<<pq[i].hh<<" "<<pq[i].mm<<' '<<pq[i].cc<<endl;
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
