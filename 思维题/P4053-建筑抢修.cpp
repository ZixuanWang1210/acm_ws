#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e5+10;
#define pii pair<int,int>
priority_queue<int> q;
int n;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    vector<pii> v(2*n);
    for(int i=1;i<=n;i++){
        cin>>v[i].second>>v[i].first;
    }
    sort(v.begin()+1,v.begin()+1+n);

    int now=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(now+v[i].second<=v[i].first){
            now+=v[i].second;
            cnt++;
            q.push(v[i].second);
        }
        else{
            if(q.top()>v[i].second){
                now=now-q.top()+v[i].second;
                q.pop();
                q.push(v[i].second);
            }
        }
    }
    
    cout<<cnt<<endl;

    return 0;
}
