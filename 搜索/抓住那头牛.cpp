#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n,k;
    cin>>n>>k;
    if(k<n){
        cout<<n-k<<endl;
        return;
    }
    vector<int> st(2*k);
    queue<pii> q;
    q.push({n,0});
    st[n]=true;
    
    while(q.size()){
        int x=q.front().first,dis=q.front().second;
        q.pop();
        if(x==k){
            cout<<dis<<endl;
            return;
        }
        
        if(x<k&&st[x+1]==false){
            q.push({x+1,dis+1});
            st[x+1]=true;
        }
        if(st[x-1]==false){
            q.push({x-1,dis+1});
            st[x-1]=true;
        }
        if(x<k&&st[2*x]==false){
            q.push({2*x,dis+1});
            st[2*x]=true;
        }
        
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
