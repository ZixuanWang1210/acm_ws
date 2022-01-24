#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int,int>
#define debug(x) cout <<#x<<": -----> "<<x<< endl;
typedef long long ll;
using namespace std;

const int N=5e5+10;
int n;
int a[N],b[N];

struct node{
    int x,y;
    bool operator<(const node&t) const{
        return a[x]+b[y] >= a[t.x]+b[t.y];
    }
    node(int X, int Y){
        x=X, y=Y;
    }
};


priority_queue<node> q;
map<pii,int> mp;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    q.push({1,1});

    for(int i=1;i<=n;i++){
        // int x=q.top().x,y=q.top().y;
        while(mp[make_pair(q.top().x,q.top().y)]) q.pop();
        int x=q.top().x,y=q.top().y;
        int sum=a[x]+b[y]; cout<<sum<<" ";
        mp[make_pair(x,y)]=1;
        q.push({x+1,y});q.push({x,y+1});
    }
    return 0;
}
