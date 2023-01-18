#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x7f7f7f7f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

void sol(){
    int n,m; cin>>n>>m;
    vector<int> v(n+1),s(n+1);
    for(int i=1;i<=n;i++) cin>>v[i],s[i]=s[i-1]+v[i];

    int sum=0;
    int res=0;
    priority_queue<int,vector<int>,greater<int>> pq2;
    priority_queue<int> pq1;
    for(int i=m+1;i<=n;i++){
        sum+=v[i];
        pq2.push(v[i]);
        if(sum<0){
            int x=pq2.top();
            pq2.pop();
            sum-=(2*x);
            res++;
        }
    }
    sum=0;
    for(int i=m;i>=2;i--){
        sum+=v[i];
        pq1.push(v[i]);
        if(sum>0){
            int x=pq1.top();
            pq1.pop();
            sum-=(2*x);
            res++;
        }
    }
    cout<<res<<endl;
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
