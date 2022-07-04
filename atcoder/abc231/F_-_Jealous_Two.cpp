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


const int maxn=2e6+10;
int a[maxn],b[maxn];
vector<int> v;

int tr[maxn],n;

int lowbit(int x){
    return x & -x;
}

void add(int a, int b){
    for(; a <= n; a += lowbit(a)) tr[a] += b;
}

int ask(int x){
    int ans = 0;
    for(; x; x -= lowbit(x)) ans += tr[x];
    return ans;
}

int get(int x){
    return lower_bound(_all(v),x)-v.begin()+1;
}

bool cmp(pii &a,pii &b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],v.push_back(a[i]);
    for(int i=1;i<=n;i++) cin>>b[i],v.push_back(b[i]);
    vector<pii> vec;
    sort(_all(v));
    v.erase(unique(_all(v)),v.end());

    for(int i=1;i<=n;i++){
        a[i]=get(a[i]),b[i]=get(b[i]);
        vec.push_back({a[i],b[i]});
    }

    int nn=n;
    n=v.size();

    sort(_all(vec),cmp);
    int sum=0;
    for(auto x:vec){
        sum+=(ask(n)-ask(x.second-1));
        add(x.second,1);
    }
    cout<<sum<<endl;

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
