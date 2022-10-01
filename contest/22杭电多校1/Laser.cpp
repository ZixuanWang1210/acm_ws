#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

vector<pii> v;
int n;

pii check(){
    for(int i=0;i<1;i++){
        for(int j=i=1;j<n;j++){
            int dx=v[i].first-v[j].first;
            int dy=v[i].second-v[j].second;
            double k=(double)abs(dy)/abs(dx);
            if(v[i].first==v[j].first) continue;
            else if(v[i].second==v[j].second) continue;
            else if(k==1) continue;
            else return {i,j};
        }
    }
    return {0,0};
}

bool check(int x,int y){
    for(int i=0;i<n;i++){
        int dx=x-v[i].first,dy=y-v[i].second;
        double k=(double)abs(dy)/abs(dx);
        // cout<<k<<endl;
        if(v[i].first==x) continue;
        else if(v[i].second==y) continue;
        else if(k==1) continue;
        else {
            return false;};
    }
    return true;
}

void sol(){
    cin>>n;
    v.clear();
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,y});
    }
    auto t=check();
    if(t==make_pair(0,0)){
        cout<<"YES"<<endl;
        return;
    }
    pii x=v[t.first],y=v[t.second];
    int x1=x.first,y1=x.second,x2=y.first,y2=y.second;

    if(check(x2,y1)||check(x1,y2)||
    check((y2-y1+x1+x2)/2,(x2-x1+y1+y2)/2)||
    check((y1-y2+x1+x2)/2,(x1-x2+y1+y2)/2)||
    check(x1-y1+y2,y2)||check(x2-y2+y1,y1)||check(x2-y1+y2,y1)||
    check(x1-y2+y1,y2)||check(x2,x1-x2+y1)||check(x1,x2-x1+y2)
    ||check(x1,x1-x2+y2)||check(x2,x2-x1+y1)
    ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    // cout<<check(3,3)<<endl;
    


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
