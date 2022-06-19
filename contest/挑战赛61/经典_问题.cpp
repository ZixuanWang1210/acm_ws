#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

long long a[10000001],c[10000002][2],n,m;
unsigned int rd;
inline int rnd(int mod,int seed)
{
    rd^=(1<<13);
    rd^=(rd>>7);
    rd^=(rd<<20);
    rd^=(rd>>3);
    rd^=(rd<<10);
    rd^=(rd<<5);
    rd^=(1<<2);
    return rd%mod+seed;
}
// 生成序列 a
void make_sequence()
{
    for(int i=1;i<=n;i++)
    {
        a[i]=i-1;
    }
    for(int i=1;i<=n;i++)
    {
        swap(a[i],a[rnd(n,1)]);
    }
}
// 生成一个询问，表示查询区间 [l,r] 的 mex 
pair<int,int> make_query()
{
    int l=rnd(n,1);
    int r=rnd(n+1-l,l);
    return make_pair(l,r);
}
map<int,int> mp;

void sol(){
    // pii ask=make_query();
    cin>>n>>m;
    make_sequence();
    c[0][0]=n;
    c[n+1][1]=n;
    for(int i=1;i<=n;i++){
        c[i][0]=min(c[i-1][0],a[i]);
        // cout<< c[i][0]<<' ';
        // mp[a[i]]=i;
        // cout<<a[i]<<' ';
    }
    // cout<<endl;
    for(int i=n;i>=1;i--){
        c[i][1]=min(c[i+1][1],a[i]);
        // cout<<c[i][1]<<' ';
        // mp[a[i]]=i;
        // // cout<<a[i]<<' ';
    }
    // cout<<endl;


    long long res=0;
    for(int i=1;i<=m;i++){
        pii ask=make_query();
        int l=ask.first,r=ask.second;
        // cout<<l<<' '<<r<<endl;
        long long ans;
        // if(l==1&&r==n) ans=n;
        // else if(l==1) ans=c[r+1][1];
        // else if(r==n) ans=c[l-1][0];
        // else 
        ans=min(c[l-1][0],c[r+1][1]);
        cout<<ans<<endl;
        res^=ans;
    }
    cout<<res<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;2
    while(_--){
        sol();
    }

    return 0;
}
