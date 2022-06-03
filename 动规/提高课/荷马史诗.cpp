#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int a[maxn];

#define int long long
#define pii pair<int,int>
priority_queue<pii,vector<pii>,greater<pii>> pq;

signed main(){
    int n,k; cin>>n>>k;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        a[i]=x;
        pq.push({x,0});
    }

    while((n-1)%(k-1)){
        pq.push({0,0});
        n++;
    }

    int ans=0;
    while(pq.size()>1){
        int s=0;
        int dep=0;
        for(int i=1;i<=k;i++){
            auto t=pq.top();
            pq.pop();
            s+=t.first;
            dep=max(dep,t.second);
        }
        ans+=s;
        pq.push({s,dep+1});
    }
    cout<<ans<<endl<<pq.top().second<<endl;
    return 0;
}