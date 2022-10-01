#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;
const int maxn=2100;
int n,m;
int get(pii a,pii b){
    int dx=a.first-b.first;
    int dy=a.second-b.second;
    return abs(dx)+abs(dy);
}

bool st[maxn*maxn];
int prime[maxn*maxn],tot;
void get_prime(int x){
    st[1]=1;
    for(int i=2;i<=n;i++){
        if(!st[i]) prime[++tot]=i;
        for(int j=1;prime[j]<=n/i;j++){
            st[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
int primes[maxn * maxn], cc;
int cnt, ans;

void init()
{ // 线性筛法
    for(int i = 2 ; i < 200010 ; i ++ )
    {
        if(!st[i]) primes[cnt ++ ] = i;
        for(int j = 0 ; primes[j] * i < 200010 ; j ++ )
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void sol(){
    cin>>n>>m;

    vector<pii> v;
    vector<pair<int,pair<int,int>>> seg;
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,y});
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            // dis[i][j]=;
            seg.push_back({get(v[i],v[j]),{i,j}});
        }
    }
    sort(_all(seg));
    int res=0;
    bitset<2005> bit[maxn];
    for(auto x:seg){
        int i=x.second.first,j=x.second.second;
        if(!st[x.first]) res+=(bit[i]^bit[j]).count();
        bit[i][j]=bit[j][i]=1;
    }
    cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // get_prime(2e5+10);
    init();
    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
