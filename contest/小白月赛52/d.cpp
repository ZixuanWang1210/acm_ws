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

void sol(){
    int n; cin>>n;
    vector<int> v(n+2),b(n+2);

    priority_queue<pii> pq;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(i==1||i==n){
            pq.push({v[i],i});
        }
        else pq.push({v[i]*2,i});
    }

    while(pq.size()){
        auto t=pq.top();
        pq.pop();

        int idx=t.second,cost=t.first;
        if(!b[idx]){
            if(idx!=1&&idx!=n) b[idx]=cost/2;
            else  b[idx]=cost;
            b[idx+1]=1,b[idx-1]=1;
        }
    }
    int res1=0;
    for(int i=2;i<=n;i++){
        res1+=abs(b[i]-b[i-1]);
    }
//======================================
    for(int i=1;i<=n;i++){
        if(i&1) b[i]=1;
        else b[i]=v[i];
    }
    for(int i=2;i<=n-1;i++){
        if(2*v[i]<v[i+1]) b[i]=1;
    }
    int res=0;
    for(int i=2;i<=n;i++){
        res+=abs(b[i]-b[i-1]);
    }
//====================================
    for(int i=1;i<=n;i++){
        if(i&1) b[i]=v[i];
        else b[i]=1;
        // cout<<b[i]<<' ';
    }
    for(int i=2;i<=n-1;i++){
        if(2*v[i]<v[i+1]) b[i]=1;
    }
    int res2=0;
    for(int i=2;i<=n;i++){
        res2+=abs(b[i]-b[i-1]);
    }
    cout<<max({res,res1,res2})<<endl;

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
