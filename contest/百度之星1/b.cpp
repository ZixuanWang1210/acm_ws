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

const int maxn=6e6+10;
int pos[maxn];

bool cmp(const pair<int,int> a, const pair<int ,int> b) 
{
    if(a.first==b.first) return a.second>b.second;
    return a.first>b.first;            /// first 小的在前


}

void sol(){
    int n,k; cin>>n>>k;
    vector<int> v(n+1);
    // priority_queue<pii,vector<pii>,less<pii>> pq;
    vector<pii> pq;
    for(int i=1;i<=n;i++) {int x; cin>>x; v[i]=x; pq.push_back({x,i});}
    sort(_all(pq),cmp);
    set<int> st;
    for(int i=1;i<=n;i++){
        st.insert(i+k);
    }

    for(auto x:pq){
        auto now=st.lower_bound(x.second);
        pos[*now]=x.second;
        st.erase(now);
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res+=(-pos[i+k]*pos[i+k]+(i+k)*(i+k))*v[pos[i+k]];
    }

    cout<<res<<endl;
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
