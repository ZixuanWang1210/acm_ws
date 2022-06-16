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

int n,m;
int ans;
vector<pii> v(60);

int cal(){
    int res=0;
    for(int i=0;i<m;i++){
        res+=v[i].first+v[i].second;
        if(i<n){
            if(v[i].first==10) res+=v[i+1].first+v[i+1].second;
            else if(v[i].first+v[i].second==10) res+=v[i+1].first;
        }
    }
    ans=max(ans,res);
    return res;
}

void simulate_anneal(){
    for(double t=1e4;t>1e-4;t*=0.99){
        int a=rand()%m,b=rand()%m;
        int x=cal();
        swap(v[a],v[b]);
        if(n+(v[n-1].first==10)==m){
            int y=cal();
            int dt=y-x;
            if(exp(dt/t)<(double)rand()/RAND_MAX) swap(v[a],v[b]);
        }
        else swap(v[a],v[b]);
    }
}

void sol(){
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    if(v[n-1].first==10){
        m=n+1;
        cin>>v[n].first>>v[n].second;
    }
    else m=n;

    for(int i=0;i<100;i++){
        simulate_anneal();
    }
    cout<<ans<<endl;


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
