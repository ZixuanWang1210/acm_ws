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
    vector<int> v(n+1),ans(n+1);
    map<int,int> cnt;
    priority_queue<pii> pq;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        cnt[v[i]]++;
    }

    int ok=v[1];
    bool all=true;
    for(int i=1;i<=n;i++){
        if(ok!=v[i]){
            all=false;
        }
    }
    if(all) {cout<<"NO"<<endl; return;}
    else cout<<"YES"<<endl;

    // for(auto x:cnt){
    //     pq.push({x.second,x.first});
    // }
    for(int i=1;i<=n;i++){
        pq.push({cnt[i],i});
    }
    // for(int i=1;i<=n;i++){
    //     pq.push(i);
    // }

    // for(int i=1;i<=n;i++){
    //     if(v[i]!=pq.top()){
    //         ans[i]=pq.top();
    //         pq.pop();
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     if(!ans[i]&&pq.top()!=v[i]){
    //         ans[i]=pq.top();
    //         pq.pop();
    //     }
    //     // else{
    //     //     cout<<"NO"<<endl;
    //     //     return;
    //     // }
    // }

    for(int i=1;i<=n;i++){
        if(v[i]!=pq.top().second){
            ans[i]=pq.top().second;
            int x=pq.top().first-1;
            int y=pq.top().second;
            pq.pop();
            // if(x!=0) pq.push({x,y});
        }
    }
    for(int i=1;i<=n;i++){
        if(!ans[i]&&pq.top().second!=v[i]){
            ans[i]=pq.top().second;
            int x=pq.top().first-1;
            int y=pq.top().second;
            pq.pop();
            // pq.push({x,y});
        }
        // else{
        //     cout<<"NO"<<endl;
        //     return;
        // }
    }
    // cout<<"YES"<<endl;
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<endl;

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
