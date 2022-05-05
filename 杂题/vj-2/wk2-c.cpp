#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=3e5+10;
int idx=1;
int a[maxn];
struct node{
    int l,r;
    bool operator<(const node&t) const{
        if(r-l==t.r-t.l) return l>t.l;
        else return r-l<t.r-t.l;
    }
};

void sol(){
    int n; cin>>n;
    memset(a,0,sizeof a);
    idx=1;
    priority_queue<node> pq;
    pq.push({1,n});

    while(pq.size()){
        auto t=pq.top();
        pq.pop();
        int l=t.l,r=t.r;
        int mid=l+r>>1;
        a[mid]=idx++;
        if(l!=mid) pq.push({l,mid-1});
        if(r!=mid) pq.push({mid+1,r});
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;



}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
